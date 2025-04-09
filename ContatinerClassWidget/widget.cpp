#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    qDebug() << qAbs(-4); // 4
    qDebug() << qSqrt(2); // 1.41421
    qDebug() << qBound(0, 10, 100); // 10

    double x = 0.1;
    double y = 0.2;
    double z = 0.3;

    qDebug() << (x + y == z); // false

    int v = 10;
    int m = 0;
    int M = 5;

    // clip을 min, max 로 구현
    v = qMax(qMin(v, M), m);
    qDebug() << v;
    qDebug() << qRound(3.14); // 3

    qDebug() << "============QbyteArray============";
    QByteArray ba("Q");
    ba.prepend("I love ");
    ba.append("t -^^*");
    ba.replace(13, 9, "by Pikmin");
    qDebug() << ba;
    ba.remove(10,3);
    qDebug() << ba;

    qDebug() << "============QChar============";
    QString str = "Hi Qt";
    QChar *data = str.data();
    qDebug() << data[1];

    while (!data->isNull()){
        qDebug() << data->unicode();
        data++;
    }

    qDebug() << "============QString============";
    QChar data2[4] = {
        QChar(0x0055),
        QChar(0x006e),
        QChar(0x10e3),
        QChar(0x03a3)
    };
    QString str2(data2, 4);  // 이건 대부분의 Qt 버전에서 정상 동작
    qDebug() << str2;

    qDebug() << "============QStringList============";
    QStringList strList;
    strList << "qt" << "tools" << "bin";
    qDebug() << strList.join("/");

    QString str3 = "I love you QT";
    QStringList words = str3.split(" ");
    qDebug() << words.length();
    for (int i = 0; i < words.length(); i++){
        qDebug() << words[i];
    }
    for (auto word: words){
        qDebug() << word;
    }
}

Widget::~Widget() {}
