#ifndef PLOT_H
#define PLOT_H

#include <QWidget>
#include "qcustomplot.h"

namespace Ui {
class Plot;
}

class Plot : public QWidget
{
    Q_OBJECT

public:
    explicit Plot(QWidget *parent = 0, std::string title = "");
    QCustomPlot* getCustomPlot();
    ~Plot();

private:
    Ui::Plot *ui;
};

#endif // PLOT_H
