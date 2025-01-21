
#include "Item.h"
#include "ItemList.h"
#include "UuidGenerator.h"

Item::Item(string content)
    : Item(std::move(content), UuidGenerator().generate()) {
}

Item::Item(string content, string id)
    : content(std::move(content))
    , id(std::move(id)) {
}

Item::Item(const char *str, const char *id1, const vector<Item> &items) {
    content = str;
    id = id1;
    sub_items = ItemList(items);
}

string Item::get_content() const {
    return content;
}

string Item::get_id() const {
    return id;
}

bool Item::operator==(const Item &other) const {
    return id == other.id;
}

const ItemList Item::get_sub_items() const {
    return sub_items;
}

bool Item::add_sub_item(const Item &item) {
    return sub_items.add_item(item);
}
