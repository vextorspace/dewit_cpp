
#include "DisplayList.h"

#include <utility>

DisplayList::DisplayList(Item root_item) : root_item(std::move(root_item)){
}

Item DisplayList::get_root() const {
    return root_item;
}

const ItemList DisplayList::display_items() const {
    return root_item.get_sub_items();
}
