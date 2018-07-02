#include "plot.h"
#include "ui_plot.h"

#include "customdrawer.h"

Plot::Plot(QWidget *parent, std::string title) :
    QWidget(parent),
    ui(new Ui::Plot){
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString(title));
}

 QCustomPlot* Plot::getCustomPlot(){
     return ui->customPlot;
 }

Plot::~Plot()
{
    delete ui;
}
