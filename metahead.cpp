#include "metahead.h"
//Конструктор пункта меню
metahead::metahead(const QString& head)
{
    QStringList buffer = head.split(" ");
    num_level_ = buffer[0].toUInt();
    name_ = buffer[1];
    status_ = buffer[2].toUShort();
    if (buffer.size() < 4)
        name_method_ = "";
    else
        name_method_ = buffer[3];
}

//Функции получения приватных полей

uint metahead::get_num_level() const
{
    return num_level_;
}

QString metahead::get_name() const
{
    return name_;
}

ushort metahead::get_status() const
{
    return status_;
}

QString metahead::get_name_method() const
{
    return name_method_;
}
