#ifndef POINTVIEWER_H
#define POINTVIEWER_H

#include "point.h"
#include <QLineEdit>

class PointViewer{
public:
    PointViewer(){}

    PointViewer(QLineEdit* x_line_edit, QLineEdit* y_line_edit, Point* point = nullptr):m_point{point},m_x_line_edit{x_line_edit},m_y_line_edit{y_line_edit}{
        bindPoint(point);
    }

    PointViewer(Point* point, QLineEdit* x_line_edit = nullptr, QLineEdit* y_line_edit = nullptr):m_point{point},m_x_line_edit{x_line_edit},m_y_line_edit{y_line_edit}{
        bindPoint(point);
    }

    void bindPoint(Point * point){
        m_point = point;
        if(point){
            setEditLineX(point->x);
            setEditLineY(point->y);
        }
    }

    void bindXEditLine(QLineEdit* x_line_edit){
        m_x_line_edit = x_line_edit;
    }

    void bindYEditLine(QLineEdit* y_line_edit){
        m_y_line_edit = y_line_edit;
    }

    void setX(double x){
        setPointX(x);
        setEditLineX(x);
    }

    void setY(double y){
        setPointY(y);
        setEditLineY(y);
    }

    void set(Point p){
        setX(p.x);
        setY(p.y);
    }

    Point get(){
        if(m_point){
            return *m_point;
        }
        return {0,0};
    }

    double x(){
        if(m_point){
            return m_point->x;
        }
        return 0.0;
    }

    double y(){
        if(m_point){
            return m_point->y;
        }
        return 0.0;
    }

    void update(){
        if(m_point){
            setEditLineX(m_point->x);
            setEditLineY(m_point->y);
        }
    }

    void setPointX(double x){
        if(m_point){
            m_point->x = x;
        }
    }

    void setPointY(double y){
        if(m_point){
            m_point->y = y;
        }
    }

private:

    void setEditLineX(double x){
        if(m_x_line_edit){
             m_x_line_edit->setText(QString::number(x));
        }
    }

    void setEditLineY(double y){
        if(m_y_line_edit){
            m_y_line_edit->setText(QString::number(y));
        }
    }

    Point* m_point;
    QLineEdit* m_x_line_edit;
    QLineEdit* m_y_line_edit;
};

#endif // POINTVIEWER_H
