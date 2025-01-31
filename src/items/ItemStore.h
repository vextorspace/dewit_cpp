
#ifndef ITEMSTORE_H
#define ITEMSTORE_H

#include <list>

#include "Item.h"

class ItemStore {
public:
    ItemStore();
    const Item *create(const string &content);
    const Item *create(const string &content, const string &id);
    const optional<const Item *> create_in(const string &content, const string &parent_id);
    const optional<const Item *> create_in(const string &content, const string &id, const string &parent_id);

    const size_t size() const;
    const vector<const Item *> get_all_items() const;
    const Item *get_root() const;

    const optional<const Item *> find_by_id(const string & parent_id);

    void remove_from(const string & child_id, const string & parent_id);

private:
    Item root;
    list<Item> items;
    optional<Item *> find_modifiable_by_id(const string & id);
};



#endif //ITEMSTORE_H
