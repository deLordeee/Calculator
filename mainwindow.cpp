#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QKeyEvent>
//Variables to store total calculation value + state of buttons of arethmetics
double calculationValue = 0.0;
bool divideTrigger = false;
bool multiplyTrigger = false;
bool plusTrigger = false;
bool minusTrigger = false;
double memoryValue = 0.0;

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//setting up ui automaticly

    ui->Display->setText(QString::number(calculationValue));//displaying calculation value
    QPushButton *numButtons[10];//array to hold references to buttons
    for(int i=0;i<10;i++){
        QString butName = "B" + QString::number(i);//getting names of buttons
        numButtons[i] = MainWindow::findChild<QPushButton *>(butName);//looking for button by there names in our ui
        connect(numButtons[i] , SIGNAL(released()),this,SLOT(NumPressed()));
    }
    connect(ui->PlusButton , SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->MinusButton , SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->MultiplyButton , SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->DivideButton , SIGNAL(released()),this,SLOT(MathButtonPressed()));
    connect(ui->ClearButton, &QPushButton::released, this, &MainWindow::ClearButton);
    connect(ui->EqualButton, &QPushButton::released, this, &MainWindow::EqualButton);
    connect(ui->MemoryAdd, &QPushButton::released, this, &MainWindow::MemoryAdd);
    connect(ui->MemoryClear, &QPushButton::released, this, &MainWindow::MemoryClear);
    connect(ui->MemoryGet, &QPushButton::released, this, &MainWindow::MemoryGet);
    connect(ui->MemorySub, &QPushButton::released, this, &MainWindow::MemorySubstruct);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::NumPressed(){
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    QString displayVal = ui->Display->text();
    if((displayVal.toDouble() == 0 || displayVal.toDouble() == 0.0)){
        ui->Display->setText(butVal);
    }
    else{
        QString newVal = displayVal +butVal;
        double dblNewVal = newVal.toDouble();
        ui->Display->setText(QString::number(dblNewVal,'g',16));
    }
}
void MainWindow::MathButtonPressed(){
    divideTrigger = false;
    multiplyTrigger = false;
    plusTrigger = false;
    minusTrigger = false;
    QString displayVal = ui->Display->text();
    calculationValue = displayVal.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString butVal = button->text();
    if(QString::compare(butVal, "/" ,Qt::CaseInsensitive) == 0){
        divideTrigger = true;
    }
    else if(QString::compare(butVal, "*" ,Qt::CaseInsensitive)== 0){
        multiplyTrigger = true;
    }
    else if(QString::compare(butVal, "+" ,Qt::CaseInsensitive)== 0){
        plusTrigger = true;
    }
    else{
        minusTrigger = true;
    }

    ui->Display->setText("");
}
double solution = 0.0;
void MainWindow::EqualButton(){

    QString displayVal = ui->Display->text();
    double dblDisplayVal = displayVal.toDouble();
    if(plusTrigger || minusTrigger || multiplyTrigger || divideTrigger){
        if(plusTrigger){
            solution = calculationValue + dblDisplayVal;
        }
        else if(minusTrigger){
            solution = calculationValue - dblDisplayVal;
        }
        else if(multiplyTrigger){
            solution = calculationValue * dblDisplayVal;
        }
        else{
            solution = calculationValue / dblDisplayVal;
        }
    }
    ui->Display->setText(QString::number(solution));
}

void MainWindow::ClearButton(){
    calculationValue = 0.0;
    ui->Display->setText(QString::number(calculationValue));
}
void MainWindow::MemoryAdd() {
    double displayVal = ui->Display->text().toDouble();
    memoryValue += displayVal;
}

void MainWindow::MemoryClear() {
    memoryValue = 0.0;
}

void MainWindow::MemoryGet() {
    ui->Display->setText(QString::number(memoryValue));
}

void MainWindow::MemorySubstruct() {
    double displayVal = ui->Display->text().toDouble();
    memoryValue -= displayVal;
}

void MainWindow::DeleteDigit() {
    QString currentDisplay = ui->Display->text();
    if (!currentDisplay.isEmpty() && (solution != currentDisplay.toDouble())) {
        currentDisplay.chop(1);
        ui->Display->setText(currentDisplay);
    }
}
void MainWindow::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_0:
        ui->B0->click();
        break;
    case Qt::Key_1:
        ui->B1->click();
        break;
    case Qt::Key_2:
        ui->B2->click();
        break;
    case Qt::Key_3:
        ui->B3->click();
        break;
    case Qt::Key_4:
        ui->B4->click();
        break;
    case Qt::Key_5:
        ui->B5->click();
        break;
    case Qt::Key_6:
        ui->B6->click();
        break;
    case Qt::Key_7:
        ui->B7->click();
        break;
    case Qt::Key_8:
        ui->B8->click();
        break;
    case Qt::Key_9:
        ui->B9->click();
        break;
    case Qt::Key_Plus:
        ui->PlusButton->click();
        break;
    case Qt::Key_Minus:
        ui->MinusButton->click();
        break;
    case Qt::Key_Asterisk:
        ui->MultiplyButton->click();
        break;
    case Qt::Key_Slash:
        ui->DivideButton->click();
        break;
    case Qt::Key_Enter:
    case Qt::Key_Return:
        ui->EqualButton->click();
        break;
    case Qt::Key_Escape:
        ui->ClearButton->click();
        break;
    case Qt::Key_Backspace:
        DeleteDigit();
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}
