#ifndef PATIENT_H
#define PATIENT_H

#include <QWidget>
#include <QTableView>
#include <QStandardItemModel>
#include "mainwindow.h"

namespace Ui {
class Patient;
}

class Patient : public QWidget
{
    Q_OBJECT

public:
    explicit Patient(QWidget *parent = 0);
    ~Patient();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_doIt_clicked();

    void on_doIt2_clicked();

    void on_doit3_clicked();

private:
    Ui::Patient *ui;
    QTableView view;
    QStandardItemModel model;
};

#endif // PATIENT_H
