#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QColor>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
//    ui->setupUi(this);
//    ui->sudokuBox->layout()->setSpacing(0);
//    for(int i=0;i<9;i++){
//        ui->sudokuBox->layout()->itemAt(i)->layout()->setSpacing(1);
//    }
    QGridLayout *mainLayout = new QGridLayout;
    QGridLayout *sudokuLayout = new QGridLayout;
    QVBoxLayout *cnfLayout = new QVBoxLayout;
    QWidget *window = new QWidget(this);
    QGroupBox *sudokuBox = new QGroupBox;
    QGroupBox *cnfBox = new QGroupBox;
    sudokuBox->setTitle("Sudoku");
    for (int i1 = 0; i1 < 9; i1++) {
        for (int i2 = 0; i2 < 9; i2++) {
            QLineEdit *singleBox = new QLineEdit;
            singleBox->setFixedSize(20, 20);
            singleBox->setMaxLength(1);
//            singleBox->setFocusPolicy(Qt::NoFocus);
            sudokuLayout->addWidget(singleBox, i1, i2);
        }
    }
    QPushButton *initialSudoku = new QPushButton("Initial Sudoku");
    QPushButton *submitSudoku = new QPushButton("Submit Sudoku");
    connect(initialSudoku, &QPushButton::clicked, this, &MainWindow::InitialSudoku);

    cnfLayout->addWidget(initialSudoku);
    cnfLayout->addWidget(submitSudoku);


    cnfBox->setLayout(cnfLayout);
    sudokuBox->setLayout(sudokuLayout);
    mainLayout->addWidget(sudokuBox, 0, 0);
    mainLayout->addWidget(cnfBox, 0, 1);
    window->setLayout(mainLayout);
    setCentralWidget(window);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::InitialSudoku() {
    SudokuSolver sudokuSolver;
}