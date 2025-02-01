//
// Created by vextorspace on 1/29/25.
//

#include "AddItem.h"
#include "display/DisplayList.h"

AddItem::AddItem(ItemStore *item_store, DisplayList *display_list) : Command("Add Item") {
    this->item_store = item_store;
    this->display_list = display_list;
}

void AddItem::execute() {
    auto content = display_list->get_input();
    item_store->create_in(content, display_list->get_selected_item()->get_id());
}
