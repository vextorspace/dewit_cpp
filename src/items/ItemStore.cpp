
#include "ItemStore.h"

ItemStore::ItemStore() {
    items = std::vector<Item>{Item("root")};
    root = &items.back();
}
const Item * ItemStore::get_root() const {
    return root;
}

const Item * ItemStore::get_selected_item() const {
    return root;
}

const Item * ItemStore::create(const string &content) {
    items.push_back(Item(content));
    root->add_item(&items.back());
    return &items.back();
}