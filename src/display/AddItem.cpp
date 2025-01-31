//
// Created by vextorspace on 1/29/25.
//

#include "AddItem.h"

AddItem::AddItem(ItemStore *item_store, DisplayList *display_list) : Command("Add Item") {
    this->item_store = item_store;
    this->display_list = display_list;
}
