
#include "ItemStore.h"

#include "UuidGenerator.h"

ItemStore::ItemStore() : root(Item("root")), items({}){
}

const Item * ItemStore::create(const string &content) {
    return create(content, UuidGenerator::generate());
}

const Item * ItemStore::create(const string &content, const string &id) {
    items.push_back(Item(content, id));
    root.add_item(&items.back());
    return &items.back();
}

const std::optional<const Item *> ItemStore::create_in(const string &content, const string &parent_id) {
    std::optional<Item *>parent = find_modifiable_by_id(parent_id);

    if (!parent.has_value()) {
        return std::nullopt;
    }

    items.push_back(Item(content));
    parent.value()->add_item(&items.back());
    return &items.back();
}


const size_t ItemStore::size() const {
    return items.size()+1;
}

const Item * ItemStore::get_root() const {
    return &root;
}

const Item * ItemStore::get_selected_item() const {
    return &root;
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

const std::optional<const Item *> ItemStore::find_by_id(const string &id) {
    return find_modifiable_by_id(id);
}


std::optional<Item *> ItemStore::find_modifiable_by_id(const string &id) {
    if (root.get_id() == id) {
        return &root;
    }
    auto it = std::find_if(items.begin(), items.end(), [&id](const Item &item) {
        return item.get_id() == id;
    });
    if (it != items.end()) {
        return &*it;
    }

    return std::nullopt;
}
