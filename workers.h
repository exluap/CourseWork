#ifndef WORKERS_H
#define WORKERS_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include "mainwindow.h"
namespace Ui {
class Workers;
}

class Workers : public QWidget
{
    Q_OBJECT

public:
    explicit Workers(QWidget *parent = 0);
    ~Workers();
    static void load(const QStandardItemModel &model);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_doIt_clicked();

    void on_doIt2_clicked();

    void on_doit3_clicked();

private:
    Ui::Workers *ui;
    QTableView view;
    QStandardItemModel model;
};

#endif // WORKERS_H
