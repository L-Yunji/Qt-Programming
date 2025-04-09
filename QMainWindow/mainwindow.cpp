#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "mdimainwindow.h"
#include "form.h"

#include <QMenu>
#include <QAction>
#include <QMenuBar>
#include <QToolBar>
#include <QDockWidget>
#include <QListWidget>
#include <QStatusBar>
#include <QDebug>
#include "targetwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 1. File 메뉴 액션 정의
    QAction* newAct = new QAction(QIcon(":/images/new.png"), tr("&New"), this);
    newAct->setShortcut(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    QAction* openAct = new QAction(QIcon(":/images/open.png"), tr("&Open"), this);
    openAct->setShortcut(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    // 2. 메뉴바 - File 메뉴 구성
    QMenu* fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);

    // 3. 메뉴바 - Option > Preference 서브메뉴 구성
    QMenu* optionMenu = menuBar()->addMenu(tr("&Option"));
    QMenu* preferenceMenu = optionMenu->addMenu(tr("&Preference"));

    QAction* generalAct = new QAction(tr("General Settings"), this);
    QAction* appearanceAct = new QAction(tr("Appearance"), this);
    QAction* shortcutsAct = new QAction(tr("Shortcuts"), this);

    connect(generalAct, &QAction::triggered, this, []() {
        qDebug() << "General Settings clicked";
    });
    connect(appearanceAct, &QAction::triggered, this, []() {
        qDebug() << "Appearance clicked";
    });
    connect(shortcutsAct, &QAction::triggered, this, []() {
        qDebug() << "Shortcuts clicked";
    });

    preferenceMenu->addAction(generalAct);
    preferenceMenu->addAction(appearanceAct);
    preferenceMenu->addAction(shortcutsAct);

    // 4. 툴바 구성
    QToolBar* fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addSeparator();

    // 5. 상태바 메시지 초기화
    statusBar()->showMessage(tr("Ready"));

    //DockWidget 설정
    dock = new QDockWidget(tr("Target"), this);
    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

    // QListWidget *customerList = new QListWidget(dock);
    // customerList->addItems(QStringList()
    //                        << "One" << "Two" << "Three" << "Four" << "Five");

    TargetWidget* targetWidget = new TargetWidget();

    dock->setWidget(targetWidget);
    addDockWidget(Qt::RightDockWidgetArea, dock);

    setCentralWidget(new MDIMainWindow());

    statusBar()->showMessage(tr("Ready"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newFile()
{
    qDebug() << Q_FUNC_INFO;
    auto mdiWindow = (MDIMainWindow*)centralWidget();
    mdiWindow->showForm();
}

void MainWindow::open()
{
    qDebug() << Q_FUNC_INFO;
    dock->show();
    dock->setFocus();
    TargetWidget* t = (TargetWidget*)dock->widget();
    t->show();
}
