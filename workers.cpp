#include "workers.h"
#include "ui_workers.h"
#include "QDebug"
Workers::Workers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Workers)
{
    ui->setupUi(this);
    QStringList headers = QStringList() << "ФИО" << "Возраст" << "Пол" << "Должность" << "Статус" << "Отделение";
    model.setHorizontalHeaderLabels(headers);
    model.setColumnCount(headers.size());

    QFile loadFile("data.json");
    if (!loadFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open save file.");
    }

    QByteArray saveData = loadFile.readAll();
    QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);
    QJsonObject json = loadDoc.object();

    // Очистка модели
    while (model.rowCount() > 0) {
        model.invisibleRootItem()->removeRow(0);
    }

    const int rowCount = json["rowCount"].toInt();
    const int columnCount = json["columnCount"].toInt();
    QJsonArray data = json["data"].toArray();

    model.setColumnCount(columnCount);

    for (int i = 0; i < rowCount; i++) {
        QJsonArray row = data[i].toArray();

        for (int j = 0; j < columnCount; j++) {
            model.setItem(i, j, new QStandardItem(row[j].toString()));
        }
    }

    view.setModel(&model);
    ui->tableView->setModel(&model);

  }

Workers::~Workers()
{
    delete ui;
}

void Workers::on_pushButton_clicked()
{
    int row=model.rowCount();
    model.insertRow(row);
    ui->tableView->selectRow(row);
    ui->tableView->setFocus();
}

void Workers::on_pushButton_3_clicked()
{
    QFile saveFile("data.json");
    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
    }

    QJsonObject json;
    json["columnCount"] = model.columnCount();
    json["rowCount"] = model.rowCount();
    QJsonArray data;
    for (int i = 0; i < model.rowCount(); i++) {
        QJsonArray row;

        for (int j = 0; j < model.columnCount(); j++) {
            row.append(QJsonValue(model.item(i, j)->text()));
        }

        data.append(row);
    }
    json["data"] = data;

    QJsonDocument saveDoc(json);
    saveFile.write(saveDoc.toJson());
}

void Workers::on_pushButton_2_clicked()
{
    int count  = ui->tableView->selectionModel()->selectedRows().count();
    for(int i=0;i < count;i++) {
        ui->tableView->model()->removeRow(ui->tableView->selectionModel()->selectedRows().at(i).row(),QModelIndex());
    }
}


void Workers::on_doIt_clicked()
{
    QFile loadFile("data.json");
       if (!loadFile.open(QIODevice::ReadOnly)) {
           qWarning("Couldn't open save file.");
       }

       QByteArray saveData = loadFile.readAll();
       QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);
       QJsonObject json = loadDoc.object();

       // Очистка модели
       while (model.rowCount() > 0) {
           model.invisibleRootItem()->removeRow(0);
       }

       const int rowCount = json["rowCount"].toInt();
       const int columnCount = json["columnCount"].toInt();
       QJsonArray data = json["data"].toArray();
       model.setColumnCount(columnCount);

       for (int i = 0; i < rowCount; i++) {
           QString deu = ui->quest1query -> text();
           QJsonArray row = data[i].toArray();
            if (!row[5].toString().compare(deu)) {
                for (int j = 0; j < columnCount; j++) {
                    model.setItem(i, j, new QStandardItem(row[j].toString()));
                }
            }
       }
       view.setModel(&model);
       ui->tableView->setModel(&model);
}

void Workers::on_doIt2_clicked()
{
    QFile loadFile("data.json");
       if (!loadFile.open(QIODevice::ReadOnly)) {
           qWarning("Couldn't open save file.");
       }

       QByteArray saveData = loadFile.readAll();
       QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);
       QJsonObject json = loadDoc.object();

       // Очистка модели
       while (model.rowCount() > 0) {
           model.invisibleRootItem()->removeRow(0);
       }

       const int rowCount = json["rowCount"].toInt();
       const int columnCount = json["columnCount"].toInt();
       QJsonArray data = json["data"].toArray();

       model.setColumnCount(columnCount);

       for (int i = 0; i < rowCount; i++) {
           QString deu = ui->questquery2->text();
           QJsonArray row = data[i].toArray();
            if (row[1].toString()<deu) {
                for (int j = 0; j < columnCount; j++) {
                    model.setItem(i, j, new QStandardItem(row[j].toString()));
                }
            }
       }
       view.setModel(&model);
       ui->tableView->setModel(&model);
}

void Workers::on_doit3_clicked()
{
    QFile loadFile("data.json");
       if (!loadFile.open(QIODevice::ReadOnly)) {
           qWarning("Couldn't open save file.");
       }

       QByteArray saveData = loadFile.readAll();
       QJsonDocument loadDoc = QJsonDocument::fromJson(saveData);
       QJsonObject json = loadDoc.object();
       // Очистка модели
       while (model.rowCount() > 0) {
           model.invisibleRootItem()->removeRow(0);
       }

       const int rowCount = json["rowCount"].toInt();
       const int columnCount = json["columnCount"].toInt();
       QJsonArray data = json["data"].toArray();

       model.setColumnCount(columnCount);


       for (int i = 0; i < rowCount; i++) {
           int deu = ui->questquery3->currentIndex();
           QJsonArray row = data[i].toArray();
            if (!row[2].toString().compare(QString::number(deu+1))) {
                for (int j = 0; j < columnCount; j++) {
                    model.setItem(i, j, new QStandardItem(row[j].toString()));
                }
            }
       }
       view.setModel(&model);
       ui->tableView->setModel(&model);
}
