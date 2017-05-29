#ifndef LABORATORY_H
#define LABORATORY_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include "mainwindow.h"

namespace Ui {
class Laboratory;
}

class Laboratory : public QWidget
{
    Q_OBJECT

public:
    explicit Laboratory(QWidget *parent = 0);
    ~Laboratory();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_doIt_clicked();

    void on_doIt2_clicked();

    void on_doit3_clicked();

private:
    Ui::Laboratory *ui;
    QTableView view;
    QStandardItemModel model;
};

#endif // LABORATORY_H
