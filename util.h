#ifndef UTIL_H
#define UTIL_H

#include "ompl/base/spaces/RealVectorStateSpace.h"
#include "ompl/geometric/PathGeometric.h"
#include "qcustomplot.h"

namespace og = ompl::geometric;
namespace ob = ompl::base;

struct Point{
  double x;
  double y;
};

namespace util{

QCPCurve *draw_points(QCustomPlot *customPlot, const QVector<double> & x, const QVector<double> & y , Qt::GlobalColor color = Qt::blue);
QCPCurve *draw_geometric_path(QCustomPlot *customPlot, og::PathGeometric * path, Qt::GlobalColor color = Qt::blue);
QCPCurve *draw_square(QCustomPlot *customPlot, Point lower_left_corner, Point top_right_corner , Qt::GlobalColor color = Qt::blue);


}

#endif // UTIL_H
