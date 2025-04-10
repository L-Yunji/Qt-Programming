#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QElapsedTimer>
#include <QLabel>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    // 시간 측정
    QElapsedTimer timer;

    // 시간을 측정하는 객체, 데이터
    // 현재 상태 (대기 <=> 게임 진행)
    int m_state; // 0: 대기 1: play
    void setState(int state);
    int state() const;

    // 현재 눌러야 할 버튼 번호
    int targetNum;

    // 언제 상태 변경? 상태 변경되면서 해야 할 일
    // 시작 버튼 누르면 -> 버튼 재배치, 타이머 리셋
    // 25개 클리어, 리셋 -> 타이머 STOP
    // 현재 눌러야 할 버튼 번호

private:
    // 시간
    QLabel* timerLabel;
    // 버튼... 25개 버튼
    QPushButton* startButton;
    QList<QPushButton*> numButton; // 25개가 1열로 늘어선 형태
    QList<QList<QPushButton*>> numButtons; // 2차원으로 관리

private:
    QTimer* sigTimer;

private:
    void initRandomNum();
    void clearNum();

private slots:
    void startButton_clicked();
    void numButton_clicked();

    void sigTimer_timeout();
};
#endif // WIDGET_H
