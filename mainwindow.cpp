#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_clicked()
{
    ui->skillText->clear();
    ui->attributeText->clear();
    ui->flawText->clear();
    ui->virtueText->clear();
    int age = ui->ageSpin->value();
    int aura = ui->auraSpin->value();
    std::string profession = ui->careerCombo->currentText().toUpper().toLocal8Bit().toStdString();
    generate(age, aura, profession);
    int length = grog.knownSkills.size();
    for (int i = 0; i < length; i++) {
        QString qstr = QString::fromStdString(grog.knownSkills[i].substr(0, grog.knownSkills[i].find(",", 0)));
        ui->skillText->append(qstr + " " + QString::number(grog.skillExperience[i]));
    }
    length = grog.attributeName.size();
    for (int i = 0; i < length; i++) {
        QString qstr = QString::fromStdString(grog.attributeName[i]) + ": " + QString::number(grog.attributeValue[i]);
        ui->attributeText->append(qstr);
    }
    length = grog.positiveQualities.size();
    for (int i = 0; i < length; i++) {
        QString qstr = QString::fromStdString(grog.positiveQualities[i].substr(0, grog.positiveQualities[i].find(",", 0)));
        ui->virtueText->append(qstr);
    }
    length = grog.negativeQualities.size();
    for (int i = 0; i < length; i++) {
        QString qstr = QString::fromStdString(grog.negativeQualities[i].substr(0, grog.negativeQualities[i].find(",", 0)));
        ui->flawText->append(qstr);
    }
}
