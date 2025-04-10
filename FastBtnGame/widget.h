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
    // Red, Blue를 보여주는 스크린
    QLabel* colorLabel;
    // 유저가 직접 누르는 버튼
    QPushButton* mainBtn;

private:
    int currentState; // 0: READY, 1: RED, 2: BLUE

    void setState(int s);
    int state() const {return currentState;}

    QTimer* waitTimer;
    QElapsedTimer reactionTimer;

private slots:
    void mainBtn_clicked();
    void on_waitTimer_timeout();
};
#endif // WIDGET_H
