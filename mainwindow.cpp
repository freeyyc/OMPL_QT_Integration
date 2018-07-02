#include "mainwindow.h"
#include "ui_mainwindow.h"

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

//    m_view_model = MainWindowViewModel(ui->customPlot);

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


    ui->envComboBox->addItems(convert_vector_to_qstringlist(m_view_model.getEnvironmentNames()));
    ui->plannerComboBox->addItems(convert_vector_to_qstringlist(m_view_model.getPlannerNames()));

    m_view_model.setCustomPlot(ui->customPlot);
    m_view_model.environmentChanged(ui->envComboBox->currentText().toStdString());
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::setStartPoint(Point start_point){
    ui->start_x->setText(QString::number(start_point.x));
    ui->start_y->setText(QString::number(start_point.y));
}

void MainWindow::setGoalPoint(Point goal_point){
    ui->goal_x->setText(QString::number(goal_point.x));
    ui->goal_y->setText(QString::number(goal_point.y));
}


void MainWindow::on_pushButton_clicked(){
    auto* planner = m_view_model.getPlanner(ui->plannerComboBox->currentText().toStdString());
    auto* environment = m_view_model.getEnvironment(ui->envComboBox->currentText().toStdString());

    Plot* plot = new Plot{nullptr, planner->getName()};
    plot->show();
    m_view_model.setCustomPlot(plot->getCustomPlot());
    m_view_model.environmentChanged(environment->getName());
    m_view_model.plan(planner,environment);
    plot->getCustomPlot()->replot();
}

void MainWindow::on_envComboBox_currentTextChanged(const QString &selectedEnvironment){
    ui->customPlot->clearPlottables();
    m_view_model.setCustomPlot(ui->customPlot);
    m_view_model.environmentChanged(selectedEnvironment.toStdString());
}
