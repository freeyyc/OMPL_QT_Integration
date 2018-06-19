#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <ompl/base/SpaceInformation.h>
#include <ompl/base/spaces/SE3StateSpace.h>
#include <ompl/geometric/planners/rrt/RRTConnect.h>
#include <ompl/geometric/SimpleSetup.h>

#include <ompl/config.h>
#include <iostream>

namespace ob = ompl::base;
namespace og = ompl::geometric;

bool isStateValid(const ob::State *state)
   {
       // cast the abstract state type to the type we expect
       const auto *se3state = state->as<ob::SE3StateSpace::StateType>();

       // extract the first component of the state and cast it to what we expect
       const auto *pos = se3state->as<ob::RealVectorStateSpace::StateType>(0);

       // extract the second component of the state and cast it to what we expect
       const auto *rot = se3state->as<ob::SO3StateSpace::StateType>(1);

       // check validity of state defined by pos & rot


       // return a value that is always true but uses the two variables we define, so we avoid compiler warnings
       return (const void*)rot != (const void*)pos;
   }

 void plan()
 {
     // construct the state space we are planning in
     auto space(std::make_shared<ob::SE3StateSpace>());

     // set the bounds for the R^3 part of SE(3)
     ob::RealVectorBounds bounds(3);
     bounds.setLow(-1);
     bounds.setHigh(1);

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
      auto planner(std::make_shared<og::RRTConnect>(si));

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
          ob::PathPtr path = pdef->getSolutionPath();
          std::cout << "Found solution:" << std::endl;

          // print the path to screen
          path->print(std::cout);
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
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
      x[i] = i/50.0 - 1; // x goes from -1 to 1
      y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-1, 1);
    ui->customPlot->yAxis->setRange(0, 1);
    ui->customPlot->replot();
    plan();
}
