//
// Created by vextorspace on 1/29/25.
//

#include "DisplayList.h"


DisplayList::DisplayList(ItemStore *item_store)
    : item_store(item_store)
      , selected_item(item_store->get_root()) {
}

const Item * DisplayList::get_root() const {
    return item_store->get_root();
}

const Item * DisplayList::get_selected_item() const {
    return item_store->get_root();
}

void DisplayList::select_item(const Item *item) {
    selected_item = item;
}

std::vector<const Item *> DisplayList::items() {
    return selected_item->get_items();
}
