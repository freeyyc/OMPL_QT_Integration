#ifndef CUSTOMDRAWER_H
#define CUSTOMDRAWER_H

#include "point.h"
#include "map2d.h"
#include "ompl/geometric/PathGeometric.h"
#include "ompl/base/PlannerData.h"
#include "qcustomplot.h"

namespace og = ompl::geometric;
namespace ob = ompl::base;

class CustomDrawer{
public:
    explicit CustomDrawer(QCustomPlot *custom_plot): m_custom_plot{custom_plot}{std::cout << "NO CONSTRUTOR " << (custom_plot == nullptr) << " " << custom_plot << std::endl;}

    QCPCurve* drawPoints(const QVector<double> & x, const QVector<double> & y , Qt::GlobalColor color = Qt::blue);
    QCPCurve* drawGeometricPath(og::PathGeometric * path, Qt::GlobalColor color = Qt::blue);
    QCPCurve* drawSquare(Point lower_left_corner, Point top_right_corner , Qt::GlobalColor color = Qt::blue);
    QCPCurve* drawLine(Point p1, Point p2, Qt::GlobalColor color = Qt::blue);
    void drawMap2d(const Map2d & map, Qt::GlobalColor color = Qt::gray);
    void drawSearchGraph(ob::PlannerData & planner_data, Qt::GlobalColor color = Qt::red);
private:
    QCustomPlot* m_custom_plot;
};

#endif // CUSTOMDRAWER_H
