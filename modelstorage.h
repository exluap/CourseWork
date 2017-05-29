#ifndef MODELSTORAGE_H
#define MODELSTORAGE_H

#include <QStandardItemModel>
#include <QStandardItem>

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
class ModelStorage
{
public:
    void load(QStandardItemModel* model);

    void save(QStandardItemModel* model);
};

#endif // MODELSTORAGE_H
