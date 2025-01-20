
#include "ItemList.h"

const size_t ItemList::size() const {
    return items.size();
}

const std::vector<Item> ItemList::get_items() const {
    return items;
}

const bool ItemList::is_empty() const {
    return items.size() == 0;
}

bool ItemList::add_item(const Item &item) {
    items.push_back(item);
    return true;
}

ItemList::ItemList(const std::vector<Item> &items)
    : items(std::move(items)){
}

