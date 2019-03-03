#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QColor>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "QList"
#include <QIntValidator>
#include "QDebug"

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
            singleBox->setValidator(new QIntValidator(1, 9, this));
        }
    }
    QPushButton *initialSudoku = new QPushButton("Initial Sudoku");
    QPushButton *submitSudoku = new QPushButton("Submit Sudoku");
    submitSudoku->setEnabled(false);
    connect(initialSudoku, &QPushButton::clicked, this, &MainWindow::InitialSudoku);
    connect(submitSudoku, &QPushButton::clicked, this, &MainWindow::SubmitSudoku);

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
    sudokuSolver.GenerateFinal();
    QList<QLineEdit *> singleBoxes = this->centralWidget()->findChildren<QLineEdit *>();
    QList<QPushButton *> buttons = this->centralWidget()->findChildren<QPushButton *>();
    for (int i = 0; i < 81; i++) {
        singleBoxes[i]->setEnabled(true);
        int temp = *(sudokuSolver.playerBoard[0] + i);
        if (temp != 0) {
            singleBoxes[i]->setText(QString::number(temp));
            singleBoxes[i]->setEnabled(false);
        } else {
            singleBoxes[i]->clear();
        }
    }
    buttons[1]->setEnabled(true);
}

void MainWindow::SubmitSudoku() {
    int playerSubmit[9][9];
    for (int i1 = 0; i1 < 9; i1++) {
        for (int i2 = 0; i2 < 9; i2++) {
            playerSubmit[i1][i2] = 0;
        }
    }
    QList<QLineEdit *> singleBoxes = this->centralWidget()->findChildren<QLineEdit *>();
    for (int i = 80; i < 81; i++) {
        int temp = singleBoxes[i]->text().toInt();
        if (temp != 0) {
            *(playerSubmit[0] + i) = temp;
        }
    }
    for (int i1 = 0; i1 < 9; i1++) {
        for (int i2 = 0; i2 < 9; i2++) {
            sudokuSolver.playerBoard[i1][i2] = playerSubmit[i1][i2];
        }
    }
    qDebug() << sudokuSolver.submit();
}