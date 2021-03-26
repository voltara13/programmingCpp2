#ifndef METAHEADLIST_H
#define METAHEADLIST_H

#include "metahead.h"

class metaheadList
{
public:
    metahead item;
    metaheadList* parent = nullptr;
    metaheadList* next = nullptr;
    metaheadList* sub_next = nullptr;

    metaheadList(const metahead&);
    static metaheadList* add(const metahead&, metaheadList*);
};

#endif // METAHEADLIST_H
