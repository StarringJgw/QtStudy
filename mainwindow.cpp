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
#include "QMessageBox"
#include "QFileDialog"
#include "QFileInfo"

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
    sudokuBox->setTitle("Sudoku Solver @Jgw");
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
    QPushButton *cheat = new QPushButton("Cheat");
    QPushButton *solveCnf = new QPushButton("Solve Cnf");
    submitSudoku->setEnabled(false);
    cheat->setEnabled(false);
    connect(initialSudoku, &QPushButton::clicked, this, &MainWindow::InitialSudoku);
    connect(submitSudoku, &QPushButton::clicked, this, &MainWindow::SubmitSudoku);
    connect(cheat, &QPushButton::clicked, this, &MainWindow::Cheat);
    connect(solveCnf, &QPushButton::clicked, this, &MainWindow::SolveCnf);

    cnfLayout->addWidget(initialSudoku);
    cnfLayout->addWidget(submitSudoku);
    cnfLayout->addWidget(cheat);
    cnfLayout->addWidget(solveCnf);

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
    buttons[2]->setEnabled(true);
    buttons[1]->repaint();
    buttons[2]->repaint();
}

void MainWindow::SubmitSudoku() {
    int playerSubmit[9][9];
    for (int i1 = 0; i1 < 9; i1++) {
        for (int i2 = 0; i2 < 9; i2++) {
            playerSubmit[i1][i2] = 0;
        }
    }
    QList<QLineEdit *> singleBoxes = this->centralWidget()->findChildren<QLineEdit *>();
    for (int i = 0; i < 81; i++) {
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
    if (sudokuSolver.submit()) {
        QMessageBox::information(this, tr("Answer"), tr("true"));
    } else
        QMessageBox::information(this, tr("Answer"), tr("false"));

}

void MainWindow::Cheat() {
//    sudokuSolver.GenerateFinal();
    QList<QLineEdit *> singleBoxes = this->centralWidget()->findChildren<QLineEdit *>();
    QList<QPushButton *> buttons = this->centralWidget()->findChildren<QPushButton *>();
    for (int i = 0; i < 81; i++) {
        singleBoxes[i]->setText(QString::number(*(sudokuSolver.answerBoard[0] + i)));
    }
    buttons[1]->setEnabled(true);

}

void MainWindow::SolveCnf() {
    QString path = QFileDialog::getOpenFileName(this, tr("Open File"), "../", "(*)");
    if (path.size() == 0)
        return;
//    qDebug()<<path;
    QFileInfo fullFile = QFileInfo(path);
//    cout << fullFile.path().toStdString()<<endl<<path.toStdString()<<endl<<fullFile.baseName().toStdString();
    auto target = cnfParser.readCnf(fullFile.path().toStdString(), path.toStdString(),
                                    fullFile.baseName().toStdString());
    satSolver.Solve(target, cnfParser.symbolNum);
    satSolver.adjust();
    satSolver.OutputLog();
    cnfParser.outputSolution(satSolver.status, satSolver.solution, satSolver.time);
    if (satSolver.status == 1) {
        QString message("Solved\nTimeOptimize(s): ");
        message = message + QString::number(satSolver.timeOpt) + "\nTimeOrign(s): " + QString::number(satSolver.time) +
                  "\nRate：" + QString::number((satSolver.time - satSolver.timeOpt) / satSolver.time) + "\n";
        QMessageBox::information(this, tr("Answer"), message);
    } else {
        QString message("Not Solved\nTimeOptimize(s): ");
        message = message + QString::number(satSolver.timeOpt) + "\nTimeOrign(s): " + QString::number(satSolver.time) +
                  "\nRate：" + QString::number((satSolver.time - satSolver.timeOpt) / satSolver.time) + "\n";
        QMessageBox::information(this, tr("Answer"), message);
    }
}