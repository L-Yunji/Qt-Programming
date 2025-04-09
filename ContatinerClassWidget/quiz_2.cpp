#include "quiz_2.h"
#include <QCoreApplication>
#include <QList>
#include <QSet>
#include <QString>
#include <QDebug>
#include <algorithm>

quiz_2::quiz_2() {
    QList<QString> words = {
        "banana", "apple", "orange", "apple", "grape", "banana", "kiwi"
    };

    // 1. QSet 으로 중복 제거
    QSet<QString> uniqueSet = QSet<QString>(words.begin(), words.end());

    // 2. 정렬을 위해 QList로 변환
    QList<QString> uniqueList = uniqueSet.values();
    std::sort(uniqueList.begin(), uniqueList.end());

    // 3. 출력
    for (const QString &word : uniqueList) {
        qDebug() << word << "(" << word.length() << ")";
    }

}
