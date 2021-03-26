#include "metahead.h"

metahead::metahead(const QString& head)
{
    QStringList buffer = head.split(" ");
    num_level = buffer[0].toUInt();
    name = buffer[1];
    status = buffer[2].toUShort();
    name_method = buffer[3];
}

uint metahead::get_num_level() const
{
    return num_level;
}

QString metahead::get_name() const
{
    return name;
}

ushort metahead::get_status() const
{
    return status;
}

QString metahead::get_name_method() const
{
    return name_method;
}
