//
// Created by vextorspace on 1/29/25.
//

#include "DisplayList.h"

#include "ConsoleInput.h"


DisplayList::DisplayList(ItemStore *item_store)
    : item_store(item_store)
      , selected_item(item_store->get_root())
      , breadcrumbs({})
{
    breadcrumbs.push_back(item_store->get_root());
}

const Item * DisplayList::get_root() const {
    return item_store->get_root();
}

const Item * DisplayList::get_selected_item() const {
    return this->selected_item;
}

void DisplayList::select_item(const Item *item) {
    selected_item = item;
    if (breadcrumbs.back()->get_id() != item->get_id()) {
        breadcrumbs.push_back(item);
    }
}

std::vector<const Item *> DisplayList::items() const {
    return selected_item->get_items();
}

std::vector<const Item *> DisplayList::get_breadcrumbs() const {
    return breadcrumbs;
}

void DisplayList::go_back() {
    if (breadcrumbs.size() > 1) {
        breadcrumbs.erase(breadcrumbs.end());
    }
}

string DisplayList::get_input() const {
    return ConsoleInput().read_line();
}
