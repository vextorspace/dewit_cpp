
#include "ItemStore.h"

ItemStore::ItemStore() : root(Item("root")), items({}){
}

const Item * ItemStore::get_root() const {
    return &root;
}

const Item * ItemStore::get_selected_item() const {
    return &root;
}

const Item * ItemStore::create(const string &content) {
    items.push_back(Item(content));
    root.add_item(&items.back());
    return &items.back();
}

const std::vector<const Item *> ItemStore::get_all_items() const {
    std::vector<const Item *> all_items;
    all_items.reserve(items.size() + 1);
    all_items.push_back(&root);
    ranges::transform(items,
                      std::back_inserter(all_items),
                      [](const Item &item) { return &item; });
    return all_items;
}

const std::optional<const Item *> ItemStore::find_by_id(const string &parent_id) {
    if (root.get_id() == parent_id) {
        return &root;
    }
    auto it = std::find_if(items.begin(), items.end(), [&parent_id](const Item &item) {
        return item.get_id() == parent_id;
    });
    if (it != items.end()) {
        return &*it;
    } else {
        return std::nullopt;
    }
}
