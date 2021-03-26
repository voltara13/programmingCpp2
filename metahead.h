#ifndef METAHEAD_H
#define METAHEAD_H

#include <QTextStream>

class metahead
{ 
private:
    uint num_level;
    QString name;
    ushort status;
    QString name_method;

public:
    metahead(const QString&);
    uint get_num_level() const;
    QString get_name() const;
    ushort get_status() const;
    QString get_name_method() const;
};

#endif // METAHEAD_H
