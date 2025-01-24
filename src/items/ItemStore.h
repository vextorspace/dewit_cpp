
#ifndef ITEMSTORE_H
#define ITEMSTORE_H

#include "Item.h"

class ItemStore {
public:
    ItemStore();
    const Item *create(const string &content);
    const std::optional<const Item *> create_in(const string &content, const string &parent_id);

    const size_t size() const;
    const std::vector<const Item *> get_all_items() const;
    const Item *get_root() const;
    const Item *get_selected_item() const;

    const std::optional<const Item *> find_by_id(const string & parent_id);

private:
    Item root;
    std::vector<Item> items;
    std::optional<Item *> find_modifiable_by_id(const string & id);
};



#endif //ITEMSTORE_H
