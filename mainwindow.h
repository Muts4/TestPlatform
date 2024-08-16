#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void handleButtonClick1();
    void handleButtonClick2();
    void openCSVFileDialog();
    void readCSVFile(const QString &fileName);
    void displayCSVData(const std::vector<std::vector<std::string>> &data);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
