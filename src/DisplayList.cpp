
#include "DisplayList.h"

#include <utility>

DisplayList::DisplayList(Item root_item) : root_item(std::move(root_item)){
    selected_item = &root_item;
}

Item DisplayList::get_root() const {
    return root_item;
}

const ItemList DisplayList::display_items() const {
    return root_item.get_sub_items();
}

const Item DisplayList::get_selected_item() const {
    return root_item;
}
