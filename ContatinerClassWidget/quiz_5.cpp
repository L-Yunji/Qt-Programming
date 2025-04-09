#include "quiz_5.h"
#include <QString>
#include <QStringList>
#include <QMap>
#include <QList>
#include <QDebug>
#include <algorithm> // std::sort

quiz_5::quiz_5() {
    QString text = "listen silent enlist google inlets banana";
    QMap<QString, QList<QString>> anagram;

    // 단어 분리
    QStringList words = text.split(' ');

    // 아나그램 기준(key)으로 정렬된 단어를 만들고, 매핑
    for (const QString& word : words) {
        QString ana_word = word;
        std::sort(ana_word.begin(), ana_word.end()); // 정렬된 문자열을 키로 사용
        anagram[ana_word].append(word); // 해당 키에 원래 단어 추가
    }

    // 결과 출력
    for (auto it = anagram.begin(); it != anagram.end(); ++it) {
        qDebug() << "\"" << it.key() << "\":" << it.value();
    }
}
