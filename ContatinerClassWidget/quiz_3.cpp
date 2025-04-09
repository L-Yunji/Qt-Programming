#include "quiz_3.h"
#include <QList>
#include <QMap>
#include <QString>
#include <QDebug>

quiz_3::quiz_3() {
    QList<QString> records = {
        "Alice 80", "Bob 90", "Alice 70", "Charlie 100", "Bob 85", "Alice 75"
    };

    QMap<QString, QList<int>> scores;

    // 입력 파싱 및 점수 누적
    for (const QString &entry : records) {
        QStringList parts = entry.split(' ', Qt::SkipEmptyParts);
        if (parts.size() != 2)
            continue;  // 잘못된 형식 무시

        QString name = parts[0];
        int score = parts[1].toInt();
        scores[name].append(score);
    }

    // 출력: QString로 한 문장 생성 후 출력
    for (auto it = scores.begin(); it != scores.end(); ++it) {
        const QString &name = it.key();
        const QList<int> &studentScores = it.value();

        int total = 0;
        for (int s : studentScores)
            total += s;

        double average = static_cast<double>(total) / studentScores.size();

        QString line = QString("%1: 총점=%2, 평균=%3")
                           .arg(name)
                           .arg(total)
                           .arg(average, 0, 'f', 1);  // 소수점 1자리 고정
        qDebug().noquote() << line;
    }

}
