
#ifndef ITEMLIST_H
#define ITEMLIST_H
#include <cstddef>
#include <vector>

#include "Item.h"

class ItemList {
public:
    [[nodiscard]] const size_t size() const;
    [[nodiscard]] const std::vector<Item> get_items() const;

    [[nodiscard]] const bool is_empty() const;

    bool add_item(const Item &item);

    ItemList() = default;

    explicit ItemList(const std::vector<Item> & items);
private:
    std::vector<Item> items;
};



#endif //ITEMLIST_H
