#ifndef METAHEADLIST_H
#define METAHEADLIST_H

#include "metahead.h"

#include <utility>

class metaheadList
{
public:
    metahead item; //����� ����
    metaheadList* parent = nullptr; //������������ ���� ������
    metaheadList* next = nullptr; //��������� ����� ����
    metaheadList* sub_next = nullptr; //�������� ����� ����

    metaheadList(metahead);
    static metaheadList* add(const metahead&, metaheadList*);
};

#endif // METAHEADLIST_H
