#include "benchmark.h"
#include "ui_benchmark.h"

Benchmark::Benchmark(QWidget *parent, EnvInterface* env, MainWindowViewModel* m_view_model, std::vector<PlannerInterface*> planners) :
    QWidget(parent),
    environment{env},
    m_view_model{m_view_model},
    benchmark_planners(planners),
    ui(new Ui::Benchmark){
    ui->setupUi(this);
    this->setWindowTitle("Config Benchmark");
}

Benchmark::~Benchmark()
{
    delete ui;
}

void Benchmark::on_maxTimelineEdit_editingFinished()
{

}

void Benchmark::on_maxMemlineEdit_editingFinished()
{

}

void Benchmark::on_runCountlineEdit_editingFinished()
{

}

void Benchmark::on_executarPushBootton_clicked()
{
    m_view_model->benchmark(benchmark_planners,environment,m_view_model->startPoint(),m_view_model->goalPoint());
}
