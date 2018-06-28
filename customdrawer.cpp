#include "customdrawer.h"
#include <iostream>

QCPCurve* CustomDrawer::drawPoints(const QVector<double> & x, const QVector<double> & y , Qt::GlobalColor color){
    if(x.size() != y.size())
        return nullptr;

    QVector<QCPCurveData> points_data(x.size());
    for(int i = 0; i < x.size(); i++){
        points_data[i] = QCPCurveData(i,x[i],y[i]);
    }
    QCPCurve *curve = new QCPCurve(m_custom_plot->xAxis, m_custom_plot->yAxis);

    curve->data()->set(points_data,true);
    curve->setPen(QPen(color));
    return curve;
}

QCPCurve* CustomDrawer::drawGeometricPath(og::PathGeometric * path, Qt::GlobalColor color){
    auto path_states = path->getStates();

    QVector<double> x(path_states.size());
    QVector<double> y(path_states.size());

    for(unsigned i = 0; i < path_states.size(); i++){
        auto *pos = path_states[i]->as<ob::RealVectorStateSpace::StateType>();
        x[i] = pos->values[0];
        y[i] = pos->values[1];
    }

    return drawPoints(x,y,color);
}

QCPCurve* CustomDrawer::drawSquare(Point lower_left_corner, Point top_right_corner , Qt::GlobalColor color){
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

    QCPCurve *curve = drawPoints(x, y, color);
    curve->setBrush(QBrush(color));
    return curve;
}

QCPCurve* CustomDrawer::drawLine(Point P1, Point P2 , Qt::GlobalColor color){
    QVector<double> x(2);
    QVector<double> y(2);

    x[0] = P1.x;
    y[0] = P1.y;

    x[1] = P2.x;
    y[1] = P2.y;

    QCPCurve *curve = drawPoints(x, y, color);
    curve->setBrush(QBrush(color));
    return curve;
}

void CustomDrawer::drawMap2d(const Map2d & map, Qt::GlobalColor color){
    auto num_obstacles = map.numObstacles();
    for(unsigned i = 0; i < num_obstacles; i++){
        auto obstacle = map.getObstacle(i);
        drawSquare(obstacle.getLowerLeftCorner(),obstacle.getTopRightCorner(),color);
    }
}

void CustomDrawer::drawSearchGraph(ob::PlannerData & planner_data, Qt::GlobalColor color){
    unsigned count = 0;
        std::cerr << "Desenhei " << count << " retas\n";
    for(unsigned i = 0; i < planner_data.numVertices(); i++){
      std::vector<unsigned int> edgeList;
      planner_data.getEdges(i,edgeList);
      Point origin{planner_data.getVertex(i)};
      for(const auto & edge:edgeList){
          Point destiny{planner_data.getVertex(edge)};
          drawLine(origin,destiny,color);
          count++;
      }
    }
    std::cerr << "Desenhei " << count << " retas\n";
}
