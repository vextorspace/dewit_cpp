//
// Created by vextorspace on 1/29/25.
//

#include "DisplayList.h"


DisplayList::DisplayList(ItemStore *item_store) : item_store(item_store) {
}

const Item * DisplayList::get_root() {
    return item_store->get_root();
}
