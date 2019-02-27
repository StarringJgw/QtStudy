//
// Created by Jgw on 27/2/19.
//
#include "mainwindow.h"
#include <QAction>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    setWindowTitle(tr("Main Window"));
    openAction = new QAction(QIcon(":/images/doc-open"), tr("&Open ..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open File"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    statusBar();
}

MainWindow::~MainWindow() {

}

void MainWindow::open() {
    QMessageBox::information(this, tr("Information"), tr("Open"));
}