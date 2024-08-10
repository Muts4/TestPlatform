#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Button.h"
#include "QMessageBox"
#include "QWidget"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyButton *button1 = new MyButton(this);
    button1->setText("Settings");
    button1->setGeometry(QRect(QPoint(0,0), QSize(125,30)));

    MyButton *button2 = new MyButton(this);
    button2->setText("Setup");
    button2->setGeometry(QRect(QPoint(130,0), QSize(125,30)));

    connect(button1, &QAbstractButton::clicked, this, &MainWindow::handleButtonClick1);
    connect(button2, &QAbstractButton::clicked, this, &MainWindow::handleButtonClick2);
}

void MainWindow::handleButtonClick1()
{
    QWidget *newWindow = new QWidget();
    newWindow->setWindowTitle("Settings");
    newWindow->resize(600,500);
    newWindow->show();
}

void MainWindow::handleButtonClick2()
{
    QWidget *newWindow = new QWidget();
    newWindow->setWindowTitle("Setup");
    newWindow->resize(600,500);
    newWindow->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
