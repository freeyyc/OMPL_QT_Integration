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

#include <ompl/config.h>
#include <iostream>

#include <boost/utility.hpp>
#include "customdrawer.h"
#include "obstacle.h"
#include "mapstatevaliditychecker.h"
#include "utils.h"
#include "Envs/envs.h"
#include "Planners/planners.h"

#include "plot.h"

namespace ob = ompl::base;
namespace og = ompl::geometric;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow){
    ui->setupUi(this);

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

    //m_view_model.environmentChanged(ui->envComboBox->currentText().toStdString());
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

void MainWindow::on_start_x_textEdited(const QString &new_value){
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
}

void MainWindow::on_start_x_editingFinished(){
    ui->customPlot->clearPlottables();
    m_view_model.setCustomPlot(ui->customPlot);
    m_view_model.environmentRedraw(ui->envComboBox->currentText().toStdString());
}


void MainWindow::on_start_y_textEdited(const QString &new_value){
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
}

void MainWindow::on_start_y_editingFinished(){
    on_start_x_editingFinished();
}

void MainWindow::on_goal_x_textEdited(const QString &new_value){
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
}

void MainWindow::on_goal_x_editingFinished(){
    on_start_x_editingFinished();
}

void MainWindow::on_goal_y_textEdited(const QString &new_value){
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
}

void MainWindow::on_goal_y_editingFinished(){
    on_start_x_editingFinished();
}
