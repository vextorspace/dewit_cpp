#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H
#include "items/ItemStore.h"


class DisplayList {
public:
    DisplayList() = delete;
    explicit DisplayList(ItemStore *item_store);

    const Item * get_root() const;

    const Item * get_selected_item() const;

    void select_item(const Item * item);

    std::vector<const Item *> items();

private:
    ItemStore *item_store;
    const Item * selected_item;
};



#endif //DISPLAYLIST_H
