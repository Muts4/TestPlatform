#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Button.h"
#include <QMessageBox>
#include <QWidget>
#include <fstream>
#include <sstream>
#include <QTableWidget>
#include <QFileDialog>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MyButton *button1 = new MyButton(this);
    button1->setText("Settings");
    button1->setGeometry(QRect(QPoint(0, 0), QSize(125, 30)));

    MyButton *button2 = new MyButton(this);
    button2->setText("Setup");
    button2->setGeometry(QRect(QPoint(130, 0), QSize(125, 30)));

    QPushButton *uploadButton = new QPushButton("Upload CSV File", this);
    uploadButton->setGeometry(QRect(QPoint(260, 0), QSize(125, 30)));


    connect(button1, &QAbstractButton::clicked, this, &MainWindow::handleButtonClick1);
    connect(button2, &QAbstractButton::clicked, this, &MainWindow::handleButtonClick2);
    connect(uploadButton, &QPushButton::clicked, this, &MainWindow::openCSVFileDialog);
}

void MainWindow::handleButtonClick1()
{
    QWidget *newWindow = new QWidget();
    newWindow->setWindowTitle("Settings");
    newWindow->resize(600, 500);
    newWindow->show();
}

void MainWindow::handleButtonClick2()
{
    QWidget *newWindow = new QWidget();
    newWindow->setWindowTitle("Setup");
    newWindow->resize(600, 500);
    newWindow->show();
}

void MainWindow::openCSVFileDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Open CSV File", "", "CSV Files (*.csv);;All Files (*)");
    if (!fileName.isEmpty())  {
        readCSVFile(fileName);
    }
    else {
        QMessageBox::warning(this, "Warning", "No file selected!");
    }
}

void MainWindow::readCSVFile(const QString &fileName)
{
    std::ifstream file(fileName.toStdString());
    if (!file.is_open()) {
        QMessageBox::critical(this, "Error", "Could not open the file!");
        return;
    }

    std::string line;
    std::vector<std::vector<std::string>> data;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        std::vector<std::string> fields;

        while (std::getline(ss, field, ',')) {
            fields.push_back(field);
        }

        data.push_back(fields);
    }

    file.close();

    displayCSVData(data);
}

void MainWindow::displayCSVData(const std::vector<std::vector<std::string>>& data)
{
    QTableWidget *tableWidget = new QTableWidget(this);
    tableWidget->setRowCount(data.size());
    tableWidget->setColumnCount(data[0].size());

    for (size_t row = 0; row < data.size(); ++row) {
        for (size_t col = 0; col < data[row].size(); ++col) {
            tableWidget->setItem(static_cast<int>(row), static_cast<int>(col), new QTableWidgetItem(QString::fromStdString(data[row][col])));
        }
    }
    tableWidget->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}
