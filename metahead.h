#ifndef METAHEAD_H
#define METAHEAD_H

#include <QTextStream>

class metahead
{ 
private:
    uint num_level_; //Номер уровня
    QString name_; //Название пункта
    ushort status_; //Статус пункта
    QString name_method_; //Название метода

public:
    metahead(const QString&);
    uint get_num_level() const;
    QString get_name() const;
    ushort get_status() const;
    QString get_name_method() const;
};

#endif // METAHEAD_H
