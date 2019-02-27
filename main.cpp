#include <iostream>
#include "QApplication"
#include "QDebug"
#include "QLabel"
#include "QPushButton"
#include "Newspaper.h"
#include "Reader.h"
#include "mainwindow.h"

using namespace ::std;

int add() {
    return 1;
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
//    Newspaper newspaper("Today");
//    Reader reader;
//    QPushButton button("send paper");
//    button.show();
//    QObject::connect(&button,&QPushButton::clicked,&newspaper,&Newspaper::send);
//    QObject::connect(&newspaper,&Newspaper::newPaper,&reader,&Reader::receive);
//    newspaper.send();
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
