#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>

#include <QStandardItemModel>
#include <QStandardItem>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_WorkersForm_clicked();

    void on_PacientForm_clicked();

    void on_LabForm_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
