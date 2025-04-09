#ifndef MDIMAINWINDOW_H
#define MDIMAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>

class MDIMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MDIMainWindow(QWidget *parent = nullptr);

private:
    QMdiSubWindow* subWindow1;
    QMdiSubWindow* subWindow2;

public:
    void showForm();

signals:
};

#endif // MDIMAINWINDOW_H
