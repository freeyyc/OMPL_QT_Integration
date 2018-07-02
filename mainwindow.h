#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mainwindowviewmodel.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setStartPoint(Point start_point);
    void setGoalPoint(Point goal_point);

private slots:
    void on_pushButton_clicked();

    void on_envComboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    MainWindowViewModel m_view_model;
};

#endif // MAINWINDOW_H
