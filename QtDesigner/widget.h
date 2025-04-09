#ifndef WIDGET_H
#define WIDGET_H
#include "modelint.h"

#include <QWidget>

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
    Ui::Widget *ui;

//Model
private:
    ModelInt* value;

private slots:
    void slider1_valueChanged(int value);
    void slider2_valueChanged(int value);
    void slider3_valueChanged(int value);

    void spinBox1_valueChanged(int val);
    void spinBox2_valueChanged(int val);
    void spinBox3_valueChanged(int val);

    void value_valueChanged(int val);

    void button1_clicked();
    void button2_clicked();
    void button3_clicked();
    void button4_clicked();
    void button5_clicked();

};



#endif // WIDGET_H
