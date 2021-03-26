#ifndef METADATA_H
#define METADATA_H

#include "metaheadlist.h"

#include <QFile>

class metadata
{
private:
    QString file_name_;

    void add_head(QString buffer);
    void read_heads_file();

public:
    metaheadList *head_list = nullptr;
	
    metadata(const QString&);
};

#endif // METADATA_H
