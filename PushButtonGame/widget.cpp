#include "widget.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <algorithm>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setMinimumSize(400, 400);

    QVBoxLayout *vLayout = new QVBoxLayout();
    QHBoxLayout *topLayout = new QHBoxLayout();
    QGridLayout *mainLayout = new QGridLayout();

    startButton = new QPushButton();
    connect(startButton, &QPushButton::clicked,
            this, &Widget::startButton_clicked);

    timerLabel = new QLabel();
    timerLabel->setStyleSheet("font:32pt;font-weight:bold;");
    timerLabel->setText("12:34");

    topLayout->addWidget(timerLabel);
    topLayout->addWidget(startButton);


    for (int y = 0; y<5; y++){
        QList<QPushButton*> row;
        for (int x = 0; x < 5; x++){
            QPushButton *b = new QPushButton();
            b->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            b->setStyleSheet("font:16pt; font-weight:bold;");

            row.append(b);
            connect(b, &QPushButton::clicked,
                    this, &Widget::numButton_clicked);
            mainLayout->addWidget(b, y, x);
        }
        numButtons.append(row);
    }

    vLayout->addLayout(topLayout);
    vLayout->addLayout(mainLayout);
    setLayout(vLayout);

    sigTimer = new QTimer(this);
    connect(sigTimer, &QTimer::timeout, this, &Widget::sigTimer_timeout);

    m_state = -1;
    setState(0);
    timerLabel->setText("00:00");

}

void Widget::sigTimer_timeout()
{
    int milisec = timer.elapsed();
    QString str = QString("%1:%2")
                      .arg(milisec/1000, 2,10,'0')
                      .arg(milisec%1000,2,10,'0');
    timerLabel->setText(str);
}

void Widget::startButton_clicked()
{
    if (state() == 1)
    {
        setState(0);
    }
    else
    {
        setState(1);
    }
}

void Widget::numButton_clicked()
{
    // 현재 누른 버튼의 번호 확인
    // 그 번호랑 targetNum랑 일치하는 지 확인
    // 일치하지 않으면 잘못눌렀으므로 아무 일도 안 일어남
    // 일치하면 -> 버튼 사라지고, targetNum++
    QPushButton* button = (QPushButton*)sender();
    auto v = button->property("num"); // 동적 속성 부여라서 타입을 모른다.
    int num = v.toInt();
    qDebug() << num;
    if(targetNum == num)
    {
        // 버튼 사라지고
        button->setText("");
        button->setDisabled(true);
        targetNum++;

        if(targetNum == 26)
        {
            // m_state = 0; 이렇게 직접 접근하는 게 아니라
            setState(0); // 함수를 통해 간접 접근한다.
            //setState 속에 상태 변화 시 일어날 일들을 정의한다.
        }
    }
}

void Widget::setState(int state)
{
    if(m_state != state)
    {
        m_state = state;
        // 시그널을 받아서 처리할 걸 여기서 직접 처리
        if(state == 1) // 대기->플레이
        {
            initRandomNum();
        }
        else // 플레이 -> 대기
        {
            clearNum();
        }
        //emit stateChanged(state);
    }
}

int Widget::state() const
{
    return m_state;
}

void Widget::initRandomNum()
{
    timer.start();
    sigTimer->start(50);

    startButton->setText("Reset");
    QList<int> nums;
    for (int i = 0; i < 25; i++)
    {
        nums.append(i+1);
    }

    std::srand(time(NULL));
    std::random_shuffle(nums.begin(), nums.end());

    int index = 0;
    for (int y = 0; y < 5; y++){
        for (int x = 0; x < 5; x++){
            auto str = QString("%1").arg(nums[index]);
            numButtons[y][x]->setText(str);
            numButtons[y][x]->setEnabled(true);
            numButtons[y][x]->setProperty("num", nums[index]); // 동적으로 멤버를 만들어 준다.
            index++;
        }
    }
    targetNum = 1;
}

void Widget::clearNum()
{
    sigTimer->stop();

    int milisec = timer.elapsed();        // 총 경과 시간 (밀리초)

    QString str = QString("%1:%2")
                      .arg(milisec/1000, 2,10,'0')
                      .arg(milisec%1000,2,10,'0');

    timerLabel->setText(str);      // 예: 01:09

    startButton->setText("시작");
    for (int y = 0; y < 5; y++)
    {
        for (int x = 0; x < 5; x++)
        {
            numButtons[y][x]->setEnabled(false);
            numButtons[y][x]->setText("");
        }
    }
}

Widget::~Widget()
{

}
