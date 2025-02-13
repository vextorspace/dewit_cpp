
#include "Item.h"

#include "UuidGenerator.h"
#include <ostream>
#include <algorithm>

#include <bits/ranges_algo.h>

Item::Item(const string content)
    : Item(std::move(content), UuidGenerator::generate()) {
}

Item::Item(const string content, const string id)
    : content(std::move(content))
      , id(std::move(id))
      , items(std::vector<const Item *>{}) {
}

void Item::set_content(const string new_content) {
    content = new_content;
}

const string Item::get_content() const {
    return content;
}

const string Item::get_id() const {
    return id;
}

const vector<const Item *> Item::get_items() const {
    return items;
}

void Item::add_item(const Item * child) {
    for (const auto* item : items) {
        if (item == child) {
            return; // If it already exists, do nothing
        }
    }
    items.push_back(child);
}

void Item::remove_item(const string &id) {
    for (auto it = items.begin(); it != items.end(); ++it) {
        if ((*it)->get_id() == id) {
            items.erase(it);
            return;
        }
    }
}

void Item::remove_child(const Item * child) {
    items.erase(std::remove(items.begin(), items.end(), child),items.end());
}

bool Item::has_child(const string &child_id) const {
    return ranges::any_of(items,
        [&child_id](const Item *item) {
            return item->get_id() == child_id;
        });
}

void PrintTo(const Item &item, std::ostream *os) {
    *os << "[" << item.id << ": " << item.get_content() << "]";
}
