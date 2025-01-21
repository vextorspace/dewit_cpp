
#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H
#include "Item.h"


class DisplayList {
public:
    DisplayList(Item root_item);

    [[nodiscard]] Item get_root() const;

    const ItemList display_items() const;

private:
    Item root_item;
};



#endif //DISPLAYLIST_H
