//
// Created by Jgw on 27/2/19.
//

#ifndef QTCLION_READER_H
#define QTCLION_READER_H

#include <QObject>
#include "QDebug"

class Reader : public QObject {
Q_OBJECT
public:
    void receive(const QString content) {
        qDebug() << "Read:" << content;
    }
};


#endif //QTCLION_READER_H
