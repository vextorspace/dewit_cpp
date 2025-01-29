#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H
#include "items/ItemStore.h"


class DisplayList {
public:
    DisplayList() = delete;
    DisplayList(ItemStore *item_store);

    const Item * get_root();
private:
    ItemStore *item_store;
};



#endif //DISPLAYLIST_H
