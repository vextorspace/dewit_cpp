
#ifndef ITEMSTORE_H
#define ITEMSTORE_H

#include "Item.h"

class ItemStore {
public:
    ItemStore();
    const Item *get_root() const;
    const Item *get_selected_item() const;
    const Item *create(const string &content);
    const std::vector<const Item *> get_all_items() const;

    const std::optional<const Item *> find_by_id(const string & parent_id);

private:
    Item root;
    std::vector<Item> items;
};



#endif //ITEMSTORE_H
