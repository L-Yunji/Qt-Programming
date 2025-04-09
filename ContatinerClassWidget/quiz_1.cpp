#include "quiz_1.h"
#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QMap>
#include <QChar>
#include <QDebug>

Quiz_1::Quiz_1() {
    QList<QString> words = {"Apple", "banana", "Zebra", "xylophone", "Night", "Quiet", "zero"};;
    QMap<QChar, int> frequency;

    for (const QString &word:words){
        QString lower = word.toLower(); // 소문자로 변환
        for (const QChar &ch : lower){
            if (ch.isLetter()){
                frequency[ch] += 1;
            }
        }
    }

    for (auto it = frequency.begin(); it != frequency.end(); it++){
        qDebug() << it.key() << ":" << it.value();
    }
}
