#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ompl/base/SpaceInformation.h>
#include <ompl/base/spaces/SE3StateSpace.h>
#include <ompl/geometric/planners/rrt/RRTConnect.h>
#include <ompl/geometric/planners/rrt/RRTstar.h>
#include <ompl/geometric/SimpleSetup.h>

#include <ompl/config.h>
#include <iostream>

namespace ob = ompl::base;
namespace og = ompl::geometric;

bool isStateValid(const ob::State *state)
   {

       // extract the first component of the state and cast it to what we expect
       const auto *pos = state->as<ob::RealVectorStateSpace::StateType>();

       return !(pos->values[0] > -50 && pos->values[0] < 50 && pos->values[1] > -50 && pos->values[1] < 50 );
   }

 void plan(const Ui::MainWindow *ui)
 {
     // construct the state space we are planning in
     auto space(std::make_shared<ob::RealVectorStateSpace>(2));

     // set the bounds for the R^3 part of SE(3)
     ob::RealVectorBounds bounds(2);
     bounds.setLow(-100);
     bounds.setHigh(100);

     space->setBounds(bounds);

     // construct an instance of  space information from this state space
     auto si(std::make_shared<ob::SpaceInformation>(space));

     // set state validity checking for this space
     si->setStateValidityChecker(isStateValid);

     // create a random start state
     ob::ScopedState<> start(space);
     start.random();

     // create a random goal state
     ob::ScopedState<> goal(space);
     goal.random();

     // create a problem instance
     auto pdef(std::make_shared<ob::ProblemDefinition>(si));

      // set the start and goal states
      pdef->setStartAndGoalStates(start, goal);

      // create a planner for the defined space
      auto planner(std::make_shared<og::RRTstar>(si));

      // set the problem we are trying to solve for the planner
      planner->setProblemDefinition(pdef);

      // perform setup steps for the planner
      planner->setup();


      // print the settings for this space
      si->printSettings(std::cout);

      // print the problem settings
      pdef->print(std::cout);

      // attempt to solve the problem within one second of planning time
      ob::PlannerStatus solved = planner->ob::Planner::solve(1.0);

      if (solved)
      {
          // get the goal representation from the problem definition (not the same as the goal state)
          // and inquire about the found path
          auto path = pdef->getSolutionPath()->as<og::PathGeometric>();
          auto path_states = path->getStates();
          std::cout << "Found solution:" << std::endl;
          std::cout << path_states.size() << std::endl;
          QVector<double> x(path_states.size()), y(path_states.size()); // initialize with entries 0..100
          int i = 0;
          for (const auto & state:path_states){
              auto *pos = state->as<ob::RealVectorStateSpace::StateType>();

              std::cout << pos->values[0] << " ";
              std::cout << pos->values[1] << std::endl;
              x[i] = pos->values[0];
              y[i] = pos->values[1];
              i++;
          }
          ui->customPlot->addGraph();
          ui->customPlot->graph(0)->setData(x, y);
          // print the path to screen
//          path->print(std::cout);
      }
      else
          std::cout << "No solution found" << std::endl;
 }

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    plan(ui);
    // generate some data:
    QVector<double> x(5), y(5); // initialize with entries 0..100
    QVector<QCPCurveData> square_data(5);

    x[0] = -50;
    y[0] = -50;

    x[1] = -50;
    y[1] = 50;

    x[2] = 50;
    y[2] = 50;

    x[3] = 50;
    y[3] = -50;

    x[4] = -50;
    y[4] = -50;

    QCPCurve *square = new QCPCurve(ui->customPlot->xAxis, ui->customPlot->yAxis);

    for(int i = 0; i<5; i++){
        square_data[i] = QCPCurveData(i,x[i],y[i]);
    }

    square->data()->set(square_data,true);
    square->setPen(QPen(Qt::blue));
    square->setBrush(QBrush(QColor(0, 0, 255, 20)));

    // create graph and assign data to it:
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-100, 100);
    ui->customPlot->yAxis->setRange(-100, 100);
    // set some basic customPlot config:
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
//    ui->customPlot->axisRect()->setupFullAxesBox();
//    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
}
