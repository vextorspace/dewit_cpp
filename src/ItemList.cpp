
#include "ItemList.h"

const size_t ItemList::size() const {
    return 0;
}

const std::vector<Item> ItemList::get_items() const {
    return items;
}

const bool ItemList::is_empty() const {
    return true;
}

ItemList::ItemList(const std::vector<Item> &items)
    : items(std::move(items)){
}
