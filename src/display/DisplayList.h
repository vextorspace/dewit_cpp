#ifndef DISPLAYLIST_H
#define DISPLAYLIST_H
#include "items/ItemStore.h"


class DisplayList {
public:
    DisplayList() = delete;
    explicit DisplayList(ItemStore *item_store);

    [[nodiscard]] const Item * get_root() const;

    [[nodiscard]] const Item * get_selected_item() const;

    void select_item(const Item * item);

    [[nodiscard]] std::vector<const Item *> items() const;

    [[nodiscard]] std::vector<const Item *> get_breadcrumbs() const ;

    void go_back();

private:
    ItemStore *item_store;
    const Item * selected_item;
    std::vector<const Item *> breadcrumbs;
};



#endif //DISPLAYLIST_H
