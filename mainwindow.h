#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void NumPressed();
    void MathButtonPressed();
    void EqualButton();
    void ClearButton();
    void MemoryAdd();
    void MemoryClear();
    void MemoryGet();
    void MemorySubstruct();
    void keyPressEvent(QKeyEvent *event);
    void DeleteDigit();
};
#endif // MAINWINDOW_H
