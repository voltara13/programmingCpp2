#ifndef METADATA_H
#define METADATA_H

#include "metaheadlist.h"

#include <QFile>
#include <utility>

class metadata
{
private:
    QString file_name_; //Поле названия файла

    void add_head(const QString& buffer);
    void read_heads_file();

public:
    metaheadList *head_list = nullptr; //"Голова" дерева каталога

    metadata(QString file_name = "data.txt");
};

#endif // METADATA_H
