#include "benchmark.h"
#include "ui_benchmark.h"

Benchmark::Benchmark(QWidget *parent, EnvInterface* env, MainWindowViewModel* m_view_model, std::vector<PlannerInterface*> planners) :
    QWidget(parent),
    environment{env},
    m_view_model{m_view_model},
    benchmark_planners(planners),
    m_max_time{1.0},
    m_max_mem{100.0},
    m_run_count{10},
    ui(new Ui::Benchmark){
    ui->setupUi(this);
    this->setWindowTitle("Config Benchmark");
    ui->maxTimelineEdit->setText(QString::number(m_max_time));
    ui->maxMemlineEdit->setText(QString::number(m_max_mem));
    ui->runCountlineEdit->setText(QString::number(m_run_count));
}

Benchmark::~Benchmark()
{
    delete ui;
}

void Benchmark::on_maxTimelineEdit_editingFinished(){
    const auto & new_value = ui->maxTimelineEdit->text();
    bool ok;
    double d_value = new_value.toDouble(&ok);
    if(ok){
        if(d_value < 0.0){
            ui->maxTimelineEdit->setText(QString::number(m_max_time));
        }else{
            m_max_time = d_value;
        }
    }else{
        ui->maxTimelineEdit->setText(QString::number(m_max_time));
    }
}

void Benchmark::on_maxMemlineEdit_editingFinished(){
    const auto & new_value = ui->maxMemlineEdit->text();
    bool ok;
    double d_value = new_value.toDouble(&ok);
    if(ok){
        if(d_value < 0.0){
            ui->maxMemlineEdit->setText(QString::number(m_max_mem));
        }else{
            m_max_mem = d_value;
        }
    }else{
        ui->maxMemlineEdit->setText(QString::number(m_max_mem));
    }
}

void Benchmark::on_runCountlineEdit_editingFinished(){
    const auto & new_value = ui->runCountlineEdit->text();
    bool ok;
    double i_value = new_value.toInt(&ok);
    if(ok){
        if(i_value < 0){
            ui->runCountlineEdit->setText(QString::number(m_run_count));
        }else{
            m_run_count = i_value;
        }
    }else{
        ui->runCountlineEdit->setText(QString::number(m_run_count));
    }
}

void Benchmark::on_executarPushBootton_clicked(){
    m_view_model->benchmark(benchmark_planners,environment,m_view_model->startPoint(),m_view_model->goalPoint(), m_max_time, m_max_mem, m_run_count);
}
