
#include "ItemList.h"
#include "Item.h"

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

const std::vector<std::string> ItemList::get_content_list() const {
    std::vector<std::string> content_list;
    for (const Item &item : items) {
        content_list.push_back(item.get_content());
    }
    return content_list;
}

const std::optional<const Item *> ItemList::find_item(const Item &item) const {
    for (const Item &existing_item : items) {
        if (existing_item.get_id() == item.get_id()) {
            return std::optional(&existing_item);
        }
    }
    return std::nullopt;
}

ItemList::ItemList(const std::vector<Item> &items)
    : items(std::move(items)){
}

ItemList::ItemList(const std::initializer_list<Item> items) {
    for (const Item &item : items) {
        this->items.push_back(item);
    }
}

