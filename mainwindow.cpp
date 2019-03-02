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
    openAction = new QAction(QIcon("../images/folder-open.png"), tr("&Open ..."), this);
    openAction->setShortcuts(QKeySequence::Open);
    openAction->setStatusTip(tr("Open File"));
    connect(openAction, &QAction::triggered, this, &MainWindow::open);

    closeAction = new QAction(tr("&Close"), this);
    connect(closeAction, &QAction::triggered, this, &MainWindow::close);

    QMenu *file = menuBar()->addMenu(tr("&File"));
    file->addAction(openAction);

    QMenu *close = menuBar()->addMenu(tr("&Close"));
    close->addAction(closeAction);

    QToolBar *toolBar = addToolBar(tr("&File"));
    toolBar->addAction(openAction);

    statusBar();
}

MainWindow::~MainWindow() {

}

void MainWindow::open() {
    QMessageBox::information(this, tr("Information"), tr("Open"));
}
