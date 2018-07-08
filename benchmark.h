#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <QWidget>
#include "mainwindowviewmodel.h"
#include "envinterface.h"

namespace Ui {
class Benchmark;
}

class Benchmark : public QWidget
{
    Q_OBJECT

public:
    explicit Benchmark(QWidget *parent, EnvInterface* env, MainWindowViewModel* m_view_model, std::vector<PlannerInterface*> planners);
    ~Benchmark();

private slots:
    void on_maxTimelineEdit_editingFinished();

    void on_maxMemlineEdit_editingFinished();

    void on_runCountlineEdit_editingFinished();

    void on_executarPushBootton_clicked();

private:
    EnvInterface* environment;
    MainWindowViewModel* m_view_model;
    std::vector<PlannerInterface*> benchmark_planners;
    double m_max_time;
    double m_max_mem;
    int m_run_count;
    Ui::Benchmark *ui;
};

#endif // BENCHMARK_H
