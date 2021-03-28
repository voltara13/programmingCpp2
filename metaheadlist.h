#ifndef METAHEADLIST_H
#define METAHEADLIST_H

#include "metahead.h"

#include <utility>

class metaheadList
{
public:
    metahead item; //Пункт меню
    metaheadList* parent = nullptr; //Родительское меню пункта
    metaheadList* next = nullptr; //Следующий пункт меню
    metaheadList* sub_next = nullptr; //Дочерний пункт меню

    metaheadList(metahead);
    static metaheadList* add(const metahead&, metaheadList*);
};

#endif // METAHEADLIST_H
