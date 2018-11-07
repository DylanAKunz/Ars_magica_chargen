#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "global.cpp"
#include <QMainWindow>
#include <string>
#include <vector>
#include <QApplication>
#include <QPushButton>
#include <iostream>
#include <map>
#include <time.h>
#include <QFile>
#include <fstream>
#include <QTextStream>
#include <QFileInfo>
#include <algorithm>



struct learnedSkills {
    std::vector<std::string> knownSkills;
    std::vector<int> skillExperience;
    std::vector<int> attributeValue;
    std::vector<std::string> attributeName;
    std::vector<std::string> positiveQualities;
    std::vector<std::string> negativeQualities;
};

extern learnedSkills grog;

void generate(int age, int aura, std::string careerSkill);

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_generateButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
