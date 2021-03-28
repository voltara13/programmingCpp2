#ifndef METAHEAD_H
#define METAHEAD_H

#include <QTextStream>

class metahead
{ 
private:
    uint num_level_; //����� ������
    QString name_; //�������� ������
    ushort status_; //������ ������
    QString name_method_; //�������� ������

public:
    metahead(const QString&);
    uint get_num_level() const;
    QString get_name() const;
    ushort get_status() const;
    QString get_name_method() const;
};

#endif // METAHEAD_H
