#ifndef MAINWINDOWVIEWMODEL_H
#define MAINWINDOWVIEWMODEL_H
#include <vector>
#include <string>
class MainWindowViewModel{
public:
    MainWindowViewModel():environments{"Estreito","Cercado","Denso"}

private:
    using std::vector;
    using std::string;

    vector<string> environments;
    vector<string> algorithms;
};

#endif // MAINWINDOWVIEWMODEL_H
