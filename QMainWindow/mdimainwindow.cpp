#include "mdimainwindow.h"
#include "form.h"

#include <QMdiArea>
#include <QPushButton>

MDIMainWindow::MDIMainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    setWindowTitle(QString::fromUtf8("My MDI"));

    QMdiArea* area = new QMdiArea();
    area->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QMdiSubWindow* subWindow1 = new QMdiSubWindow();
    subWindow1->resize(300, 200);
    QPushButton *btn = new QPushButton(QString("Button"));
    subWindow1->setWidget(btn);

    QMdiSubWindow* subWindow2 = new QMdiSubWindow();
    subWindow2->resize(300, 200);
    Form* form = new Form();
    subWindow2->setWidget(form);

    area->addSubWindow(subWindow1);
    area->addSubWindow(subWindow2);
    setCentralWidget(area);
}

void MDIMainWindow::showForm()
{
    QMdiArea* area = (QMdiArea*)centralWidget();
    auto list = area->subWindowList();
    Form* form = (Form*)list[1]->widget();
    list[1]->show();
    form->show();
    form->setFocus();
}
