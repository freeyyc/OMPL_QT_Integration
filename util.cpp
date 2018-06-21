#include "util.h"

namespace util{

QCPCurve *draw_points(QCustomPlot *customPlot, const QVector<double> & x, const QVector<double> & y , Qt::GlobalColor color){
    if(x.size() != y.size())
        return nullptr;

    QVector<QCPCurveData> points_data(x.size());
    for(int i = 0; i < x.size(); i++){
        points_data[i] = QCPCurveData(i,x[i],y[i]);
    }
    QCPCurve *curve = new QCPCurve(customPlot->xAxis, customPlot->yAxis);

    curve->data()->set(points_data,true);
    curve->setPen(QPen(color));
    return curve;
}

QCPCurve *draw_geometric_path(QCustomPlot *customPlot, og::PathGeometric * path, Qt::GlobalColor color){
    auto path_states = path->getStates();

    QVector<double> x(path_states.size());
    QVector<double> y(path_states.size());

    for(unsigned i = 0; i < path_states.size(); i++){
        auto *pos = path_states[i]->as<ob::RealVectorStateSpace::StateType>();
        x[i] = pos->values[0];
        y[i] = pos->values[1];
    }

    return draw_points(customPlot,x,y,color);
}

QCPCurve *draw_square(QCustomPlot *customPlot, Point lower_left_corner, Point top_right_corner , Qt::GlobalColor color){
    QVector<double> x(5);
    QVector<double> y(5);

    x[0] = lower_left_corner.x;
    y[0] = lower_left_corner.y;

    x[1] = lower_left_corner.x;
    y[1] = top_right_corner.y;

    x[2] = top_right_corner.x;
    y[2] = top_right_corner.y;

    x[3] = top_right_corner.x;
    y[3] = lower_left_corner.y;

    x[4] = lower_left_corner.x;
    y[4] = lower_left_corner.y;

    QCPCurve *curve = draw_points(customPlot, x, y, color);
    curve->setBrush(QBrush(color));
    return curve;
}

QCPCurve *draw_line(QCustomPlot *customPlot, Point P1, Point P2 , Qt::GlobalColor color){
    QVector<double> x(2);
    QVector<double> y(2);

    x[0] = P1.x;
    y[0] = P1.y;

    x[1] = P2.x;
    y[1] = P2.y;

    QCPCurve *curve = draw_points(customPlot, x, y, color);
    curve->setBrush(QBrush(color));
    return curve;
}

Point convert_vertex(ob::PlannerDataVertex& vertex){
    auto * state = vertex.getState()->as<ob::RealVectorStateSpace::StateType>();
    return Point{state->values[0],state->values[1]};
}

}
