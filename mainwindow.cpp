#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <math.h>

#include <ompl/base/SpaceInformation.h>
#include <ompl/base/PlannerData.h>
#include <ompl/base/spaces/SE3StateSpace.h>
#include <ompl/geometric/planners/rrt/RRTConnect.h>
#include <ompl/geometric/planners/rrt/RRTstar.h>
#include <ompl/geometric/planners/rrt/RRT.h>
#include <ompl/geometric/planners/sst/SST.h>
#include <ompl/geometric/planners/kpiece/KPIECE1.h>
#include <ompl/geometric/planners/kpiece/LBKPIECE1.h>
#include <ompl/geometric/planners/prm/PRM.h>
#include <ompl/geometric/planners/cforest/CForest.h>
#include <ompl/geometric/SimpleSetup.h>
#include <ompl/tools/benchmark/Benchmark.h>

#include <ompl/config.h>
#include <iostream>

#include <boost/utility.hpp>
#include "customdrawer.h"
#include "obstacle.h"
#include "mapstatevaliditychecker.h"
#include "utils.h"
#include "Envs/envs.h"
#include "Planners/planners.h"
#include "rangeconfiguration.h"
#include "goalbiasconfiguration.h"


#include "plot.h"
#include "benchmark.h"

namespace ob = ompl::base;
namespace og = ompl::geometric;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

    this->setWindowTitle("Planejador de Rotas");

    m_view_model.addEnviroment(new DensoEnv());
    m_view_model.addEnviroment(new CercadoEnv());
    m_view_model.addEnviroment(new EstreitoEnv());


    m_view_model.addPlanner(new ESTPlanner());
    m_view_model.addPlanner(new KPIECEPlanner());
    m_view_model.addPlanner(new LazyPRMPlanner());
    //m_view_model.addPlanner(new LazyPRMStarPlanner());
    m_view_model.addPlanner(new LazyRRTPlanner());
    m_view_model.addPlanner(new PRMPlanner());
    //m_view_model.addPlanner(new PRMStarPlanner());
    m_view_model.addPlanner(new RRTConnectPlanner());
    m_view_model.addPlanner(new RRTPlanner());
    m_view_model.addPlanner(new RRTSharpPlanner());
    m_view_model.addPlanner(new RRTStarPlanner());
    m_view_model.addPlanner(new SBLPlanner());
    m_view_model.addPlanner(new SSTPlanner());

    m_menu_variables = MenuVariables{PointViewer{ui->start_x,ui->start_y},PointViewer{ui->goal_x,ui->goal_y}};

    m_menu_variables.startPoint().bindPoint(&m_view_model.startPoint());
    m_menu_variables.goalPoint().bindPoint(&m_view_model.goalPoint());

    m_view_model.setMenuVariables(&m_menu_variables);
    m_view_model.setCustomPlot(ui->customPlot);

    ui->envComboBox->addItems(convert_vector_to_qstringlist(m_view_model.getEnvironmentNames()));
    ui->plannerComboBox->addItems(convert_vector_to_qstringlist(m_view_model.getPlannerNames()));
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::on_pushButton_clicked(){
    auto* planner = m_view_model.getPlanner(ui->plannerComboBox->currentText().toStdString());
    auto* environment = m_view_model.getEnvironment(ui->envComboBox->currentText().toStdString());

    Plot* plot = new Plot{nullptr, planner->getName()};
    plot->show();
    m_view_model.setCustomPlot(plot->getCustomPlot());
    m_view_model.environmentRedraw(environment->getName());
    m_view_model.plan(planner,environment,m_view_model.startPoint(),m_view_model.goalPoint());
    m_view_model.drawStartGoalPoints(m_view_model.startPoint(),m_view_model.goalPoint());
    plot->getCustomPlot()->replot();
}

void MainWindow::on_envComboBox_currentTextChanged(const QString &selectedEnvironment){
    ui->customPlot->clearPlottables();
    m_view_model.setCustomPlot(ui->customPlot);
    m_view_model.environmentChanged(selectedEnvironment.toStdString());
}

void MainWindow::on_plannerComboBox_currentTextChanged(const QString &selectedPlanner){
    auto * planner_interface = m_view_model.getPlanner(selectedPlanner.toStdString());
    if(planner_interface){
        if(auto * configuration = planner_interface->getConfigurations()->getConfiguration(RangeConfiguration().getName())){
            ui->rangeLabel->show();
            ui->rangeLineEdit->show();
            auto* range_configuration = static_cast<RangeConfiguration*>(configuration);
            ui->rangeLineEdit->setText(QString::number(range_configuration->getRange()));
        }else{
            ui->rangeLabel->hide();
            ui->rangeLineEdit->hide();
        }
        if(auto * configuration = planner_interface->getConfigurations()->getConfiguration(GoalBiasConfiguration().getName())){
            ui->goalBiasLabel->show();
            ui->goalBiasLineEdit->show();
            auto* goal_bias_configuration = static_cast<GoalBiasConfiguration*>(configuration);
            ui->goalBiasLineEdit->setText(QString::number(goal_bias_configuration->getGoalBias()));
        }else{
            ui->goalBiasLabel->hide();
            ui->goalBiasLineEdit->hide();
        }
    }
}

void MainWindow::pointsEditingFinished(){
    ui->customPlot->clearPlottables();
    m_view_model.setCustomPlot(ui->customPlot);
    m_view_model.environmentRedraw(ui->envComboBox->currentText().toStdString());
}

void MainWindow::on_start_x_editingFinished(){
    const auto & new_value = ui->start_x->text();
    bool ok;
    double d_value = new_value.toDouble(&ok);
    if(ok){
        double max_value{100};
        if(std::abs(d_value) > max_value){
            if(d_value > 0){
                m_menu_variables.startPoint().setX(max_value);
            }else{
                m_menu_variables.startPoint().setX(-max_value);
            }
        }else{
            m_menu_variables.startPoint().setPointX(d_value);
        }
    }else{
        ui->start_x->setText(QString::number(m_menu_variables.startPoint().x()));
    }
    pointsEditingFinished();
}

void MainWindow::on_start_y_editingFinished(){
    const auto & new_value = ui->start_y->text();
    bool ok;
    double d_value = new_value.toDouble(&ok);
    if(ok){
        double max_value{100};
        if(std::abs(d_value) > max_value){
            if(d_value > 0){
                m_menu_variables.startPoint().setY(max_value);
            }else{
                m_menu_variables.startPoint().setY(-max_value);
            }
        }else{
            m_menu_variables.startPoint().setPointY(d_value);
        }
    }else{
        ui->start_y->setText(QString::number(m_menu_variables.startPoint().y()));
    }
    pointsEditingFinished();
}

void MainWindow::on_goal_x_editingFinished(){
    const auto & new_value = ui->goal_x->text();
    bool ok;
    double d_value = new_value.toDouble(&ok);
    if(ok){
        double max_value{100};
        if(std::abs(d_value) > max_value){
            if(d_value > 0){
                m_menu_variables.goalPoint().setX(max_value);
            }else{
                m_menu_variables.goalPoint().setX(-max_value);
            }
        }else{
            m_menu_variables.goalPoint().setPointX(d_value);
        }
    }else{
        ui->goal_x->setText(QString::number(m_menu_variables.goalPoint().x()));
    }
    pointsEditingFinished();
}

void MainWindow::on_goal_y_editingFinished(){
    const auto & new_value = ui->goal_y->text();
    bool ok;
    double d_value = new_value.toDouble(&ok);
    if(ok){
        double max_value{100};
        if(std::abs(d_value) > max_value){
            if(d_value > 0){
                m_menu_variables.goalPoint().setY(max_value);
            }else{
                m_menu_variables.goalPoint().setY(-max_value);
            }
        }else{
            m_menu_variables.goalPoint().setPointY(d_value);
        }
    }else{
        ui->goal_y->setText(QString::number(m_menu_variables.goalPoint().y()));
    }
    pointsEditingFinished();
}

void MainWindow::on_rangeLineEdit_editingFinished(){
    const auto & new_value = ui->rangeLineEdit->text();
    bool ok;
    double d_value = new_value.toDouble(&ok);
    if(auto * planner_interface = m_view_model.getPlanner(ui->plannerComboBox->currentText().toStdString())){
        if(auto * configuration_interface = planner_interface->getConfigurations()){
            if(auto * configuration = configuration_interface->getConfiguration(RangeConfiguration().getName())){
                auto * range_configuration = static_cast<RangeConfiguration*>(configuration);
                if(ok){
                    if(d_value < 0.0){
                        range_configuration->setRange(0.0);
                        ui->rangeLineEdit->setText(QString::number(range_configuration->getRange()));
                    }else{
                        range_configuration->setRange(d_value);
                        ui->rangeLineEdit->setText(QString::number(range_configuration->getRange()));
                    }
                }else{
                    ui->rangeLineEdit->setText(QString::number(range_configuration->getRange()));
                }
            }
        }
    }
}


void MainWindow::on_goalBiasLineEdit_editingFinished(){
    const auto & new_value = ui->goalBiasLineEdit->text();
    bool ok;
    double d_value = new_value.toDouble(&ok);
    if(auto * planner_interface = m_view_model.getPlanner(ui->plannerComboBox->currentText().toStdString())){
        if(auto * configuration_interface = planner_interface->getConfigurations()){
            if(auto * configuration = configuration_interface->getConfiguration(GoalBiasConfiguration().getName())){
                auto * goal_bias_configuration = static_cast<GoalBiasConfiguration*>(configuration);
                if(ok){
                    if(d_value < 0.0){
                        goal_bias_configuration->setGoalBias(0.0);
                        ui->goalBiasLineEdit->setText(QString::number(goal_bias_configuration->getGoalBias()));
                    }else if(d_value > 1.0){
                        goal_bias_configuration->setGoalBias(1.0);
                        ui->goalBiasLineEdit->setText(QString::number(goal_bias_configuration->getGoalBias()));
                    }else{
                        goal_bias_configuration->setGoalBias(d_value);
                        ui->goalBiasLineEdit->setText(QString::number(goal_bias_configuration->getGoalBias()));
                    }
                }else{
                    ui->goalBiasLineEdit->setText(QString::number(goal_bias_configuration->getGoalBias()));
                }
            }
        }
    }
}


void MainWindow::on_adicionarPushButton_clicked(){
    auto* planner = m_view_model.getPlanner(ui->plannerComboBox->currentText().toStdString());
    benchmark_planners.push_back(planner);
}

void MainWindow::on_executarPushButton_clicked(){
    auto* environment = m_view_model.getEnvironment(ui->envComboBox->currentText().toStdString());

    Benchmark* benchmark = new Benchmark{nullptr, environment, &m_view_model, benchmark_planners};
    benchmark->show();
}

void MainWindow::on_limparPushButton_clicked()
{
    benchmark_planners.clear();
}
