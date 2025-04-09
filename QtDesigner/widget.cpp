#include "widget.h"
#include "./ui_widget.h"

#include <QInputDialog>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    value = new ModelInt();

    connect(ui->slider1, &QSlider::valueChanged,
            this, &Widget::slider1_valueChanged);
    connect(ui->slider2, &QSlider::valueChanged,
            this, &Widget::slider2_valueChanged);
    connect(ui->slider3, &QSlider::valueChanged,
            this, &Widget::slider3_valueChanged);

    connect(ui->spinBox1, &QSpinBox::valueChanged,
            this, &Widget::spinBox1_valueChanged);
    connect(ui->spinBox2, &QSpinBox::valueChanged,
            this, &Widget::spinBox2_valueChanged);
    connect(ui->spinBox3, &QSpinBox::valueChanged,
            this, &Widget::spinBox3_valueChanged);

    connect(value, &ModelInt::valueChanged,
            this, &Widget::value_valueChanged);

    value->setValue(30);

    connect(ui->pushButton1, &QPushButton::clicked,
            this, &Widget::button1_clicked);
    connect(ui->pushButton2, &QPushButton::clicked,
            this, &Widget::button2_clicked);
    connect(ui->pushButton3, &QPushButton::clicked,
            this, &Widget::button3_clicked);
    connect(ui->pushButton4, &QPushButton::clicked,
            this, &Widget::button4_clicked);
    connect(ui->pushButton5, &QPushButton::clicked,
            this, &Widget::button5_clicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::slider1_valueChanged(int val)
{
    value->setValue(val);
}
void Widget::slider2_valueChanged(int val)
{
    value->setValue(val);
}
void Widget::slider3_valueChanged(int val)
{
    value->setValue(val);
}

void Widget::spinBox1_valueChanged(int val)
{
    value->setValue(val);
}
void Widget::spinBox2_valueChanged(int val)
{
    value->setValue(val);
}
void Widget::spinBox3_valueChanged(int val)
{
    value->setValue(val);
}

void Widget::value_valueChanged(int val)
{
    ui->spinBox1->setValue(val);
    ui->spinBox2->setValue(val);
    ui->spinBox3->setValue(val);
    ui->slider1->setValue(val);
    ui->slider2->setValue(val);
    ui->slider3->setValue(val);
}

void Widget::button1_clicked() {
    bool retValue;
    int i = QInputDialog::getInt(this, "정수입력", "퍼센트:",
                                 25, 0, 100, 1, &retValue);
    if (retValue)
        qDebug("true %d", i);
}

//Modal
void Widget::button2_clicked() {
    QStringList items;
    items << "봄" << "여름" << "가을" << "겨울";
    bool ok;
    QString item = QInputDialog::getItem(this, "항목선택", "계절 선택: ", items, 0, true, &ok);

    ui->label->setText(item);
}

void Widget::button3_clicked() {
    bool retValue;
    int i = QInputDialog::getInt(this, "정수입력", "퍼센트:",
                                 25, 0, 100, 1, &retValue);
    if (retValue)
    {
        value->setValue(i);
        qDebug("true %d", i);
        ui->label->setText(QString("%1").arg(i));
    }
}

void Widget::button4_clicked() {
    bool retValue;
    int i = QInputDialog::getInt(this, "정수입력", "퍼센트:",
                                 25, 0, 100, 1, &retValue);
    if (retValue)
    {
        value->setValue(i);
        qDebug("true %d", i);
        ui->label->setText(QString("%1").arg(i));
    }
}

void Widget::button5_clicked() {
    bool retValue;
    int i = QInputDialog::getInt(this, "정수입력", "퍼센트:",
                                 25, 0, 100, 1, &retValue);
    if (retValue)
    {
        value->setValue(i);
        qDebug("true %d", i);
        ui->label->setText(QString("%1").arg(i));
    }
}

