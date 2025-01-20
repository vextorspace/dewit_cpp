
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
};



#endif //ITEMLIST_H
