
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
    if (std::any_of(items.begin(), items.end(),
        [&item](const Item &existing_item) {
            return existing_item.get_id() == item.get_id();
        })) {
        return false; // Do not add the item if ID already exists
    }
    items.push_back(item);
    return true;
}

ItemList::ItemList(const std::vector<Item> &items)
    : items(std::move(items)){
}

