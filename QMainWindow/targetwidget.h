#ifndef TARGETWIDGET_H
#define TARGETWIDGET_H

#include <QWidget>

namespace Ui {
class TargetWidget;
}

class TargetWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TargetWidget(QWidget *parent = nullptr);
    ~TargetWidget();

private:
    Ui::TargetWidget *ui;

};

#endif // TARGETWIDGET_H
