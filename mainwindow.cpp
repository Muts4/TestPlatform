#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Button.h"
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyButton *button = new MyButton(this);
    button->setText("Click this button");
    button->setGeometry(QRect(QPoint(50,50), QSize(100,30)));

    connect(button, &QAbstractButton::clicked, this, &MainWindow::handleButtonClick);
}

void MainWindow::handleButtonClick()
{
    QMessageBox::information(this, "Button Clicked", "You clicked it");
}

MainWindow::~MainWindow()
{
    delete ui;
}
