
#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H
#include "Item.h"


class DisplayList {
public:
    DisplayList(Item root_item);

    [[nodiscard]] Item get_root() const;

    const ItemList display_items() const;

    const Item get_selected_item() const;

private:
    Item root_item;
    Item *selected_item;
};



#endif //DISPLAYLIST_H
