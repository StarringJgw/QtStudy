#include <iostream>
#include "QApplication"
#include "QDebug"
#include "mainwindow.h"
using namespace ::std;

int add() {
    return 1;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
