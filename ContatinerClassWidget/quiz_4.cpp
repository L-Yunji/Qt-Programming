#include "quiz_4.h"
#include <QCoreApplication>
#include <QString>
#include <QStringList>
#include <QDebug>

quiz_4::quiz_4() {
    QString text = "A curious cat, always alert, observed an ant. Another animal? Absolutely!";

    // 1. 기호 제거
    text.remove(',').remove('.').remove('?').remove('!');

    // 2. 소문자로 변환
    text = text.toLower();

    // 3. 공백으로 단어 분리
    QStringList words = text.split(' ', Qt::SkipEmptyParts);

    // 4. a로 시작하는 단어 개수 세기
    int count = 0;
    for (const QString &word : words) {
        if (word.startsWith('a')) {
            count++;
        }
    }

    int maxLength = 0;
    QString maxWord;
    for (const QString &word: words){
        if (maxLength < word.length()){
            maxLength = word.length();
        }
    }
}
