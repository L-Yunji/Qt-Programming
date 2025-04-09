#include "targetwidget.h"
#include "ui_targetwidget.h"

TargetWidget::TargetWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TargetWidget)
{
    ui->setupUi(this);
}

TargetWidget::~TargetWidget()
{
    delete ui;
}
