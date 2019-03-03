#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QDebug"
#include "SatSolver/myList.h"
#include "SatSolver/SudokuSolver.h"
#include "QGroupBox"
namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void InitialSudoku();

    void SubmitSudoku();

    void Cheat();
private:
    Ui::MainWindow *ui;
    SudokuSolver sudokuSolver;
};

#endif // MAINWINDOW_H
