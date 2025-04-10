#include "widget.h"

#include <QVBoxLayout>
#include <QRandomGenerator>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(400,200);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    colorLabel = new QLabel("READY");
    colorLabel->setAlignment(Qt::AlignCenter);
    colorLabel->setStyleSheet("font-size: 16px; font-weight: bold;");

    mainBtn = new QPushButton("누르기");
    mainBtn->setMinimumSize(100, 50);
    connect(mainBtn, &QPushButton::clicked, this, &Widget::mainBtn_clicked);

    mainLayout->addWidget(colorLabel);
    mainLayout->addWidget(mainBtn);

    setLayout(mainLayout);

    waitTimer = new QTimer(this);
    waitTimer->setSingleShot(true);
    connect(waitTimer, &QTimer::timeout, this, &Widget::on_waitTimer_timeout);

    setState(0);
}

void Widget::mainBtn_clicked()
{
    if (state() == 0)
    {
        setState(1);
        int randTime = QRandomGenerator::global()->bounded(1000, 5000); // 1~5초
        waitTimer->start(randTime);
        qDebug() << "랜덤 타이머 시작: " << randTime << "ms";
    }
    else if (state() == 2) {
        int elapsed = reactionTimer.elapsed();
        colorLabel->setText(QString("반응 속도: %1 ms").arg(elapsed));
        setState(3); // 결과 상태로 전환
    }
    else if (state() == 3) {
        setState(0); // READY로 돌아감
    }
    else {
        setState(0); // READY로 돌아감
    }
}

void Widget::on_waitTimer_timeout()
{
    setState(2); // BLUE 상태로 전환
    reactionTimer.start();
}

void Widget::setState(int s)
{
    currentState = s;

    switch (s) {
    case 0: // READY
        colorLabel->setText("READY");
        mainBtn->setText("시작");
        mainBtn->setStyleSheet("background-color: none;");
        break;

    case 1: // RED
        colorLabel->setText("대기 중...");
        mainBtn->setText("...");
        mainBtn->setStyleSheet("background-color: red;");
        break;

    case 2: // BLUE
        colorLabel->setText("지금 눌러!");
        mainBtn->setText("눌러!");
        mainBtn->setStyleSheet("background-color: blue;");
        mainBtn->setEnabled(true);
        break;
    case 3: // RESULT
        mainBtn->setText("다시 시작");
        mainBtn->setStyleSheet("background-color: lightgray;");
        mainBtn->setEnabled(true);
        break;
    }

}


Widget::~Widget()
{
}
