//
// Created by Jgw on 27/2/19.
//

#ifndef QTCLION_NEWSPAPER_H
#define QTCLION_NEWSPAPER_H

#include "QObject"

class Newspaper : public QObject {
Q_OBJECT
private:
    QString mName;
public:
    Newspaper(const QString name) {
        mName = name;
    }

    void send() {
        newPaper(mName);
    }

signals:

    void newPaper(const QString &name);
};

#endif //QTCLION_NEWSPAPER_H
