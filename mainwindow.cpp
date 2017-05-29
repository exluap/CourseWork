#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "workers.h"
#include "patient.h"
#include "laboratory.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_WorkersForm_clicked()
{
    Workers *workers = new Workers();

    workers->show();
}



void MainWindow::on_PacientForm_clicked()
{
    Patient *patient = new Patient();

    patient->show();
}

void MainWindow::on_LabForm_clicked()
{
    Laboratory *lab = new Laboratory();

    lab->show();
}
