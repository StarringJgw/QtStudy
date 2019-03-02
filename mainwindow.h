//
// Created by Jgw on 27/2/19.
//

#ifndef QTCLION_MAINWINDOW_H
#define QTCLION_MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

    ~MainWindow();

private:
    void open();
    QAction *openAction;
    QAction *closeAction;
};

#endif //QTCLION_MAINWINDOW_H
