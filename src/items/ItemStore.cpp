
#include "ItemStore.h"

#include <bits/ranges_algo.h>

#include "UuidGenerator.h"

ItemStore::ItemStore() : root(Item("root")), items({}){
}

const Item * ItemStore::create(const string &content) {
    return create(content, UuidGenerator::generate());
}

const Item * ItemStore::create(const string &content, const string &id) {
    std::optional<const Item *> already_there = find_by_id(id);
    if (already_there.has_value()) {
        return already_there.value();
    }
    items.push_back(Item(content, id));
    root.add_item(&items.back());
    return &items.back();
}

const std::optional<const Item *> ItemStore::create_in(const string &content, const string &parent_id) {
    return create_in(content, UuidGenerator::generate(), parent_id);
}

const optional<const Item *> ItemStore::create_in(const string &content, const string &id, const string &parent_id) {
    std::optional<Item *>parent = find_modifiable_by_id(parent_id);
    std::optional<const Item *> already_there = find_by_id(id);

    if (!parent.has_value()) {
        return std::nullopt;
    }

    if (already_there.has_value()) {
        parent.value()->add_item(already_there.value());
        return already_there.value();
    }

    items.push_back(Item(content, id));
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

void ItemStore::remove_from(const string &child_id, const string &parent_id) {
    auto parent = find_modifiable_by_id(parent_id);
    auto child = find_by_id(child_id);

    if (parent.has_value() && child.has_value()) {
        parent.value()->remove_child(child.value());
    } else {
        std::cout << "=============== ERRAR =============" << std::endl;
    }

    bool references_remain = ranges::any_of(items,
                                            [&child_id](const Item &parent) {
                                                return parent.has_child(child_id);
                                            });

    if (!references_remain) {
        items.remove_if([&child_id](const Item &item) {
            return item.get_id() == child_id;
        });
    }
}


std::optional<Item *> ItemStore::find_modifiable_by_id(const string &id) {
    if (root.get_id() == id) {
        return &root;
    }


    auto found = std::ranges::find_if(
        items,
        [&id](const Item &item) {
            return item.get_id() == id;
        });


    if (found != items.end()) {
        return std::to_address(found);
    }

    return std::nullopt;
}
