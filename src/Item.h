
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include "ItemList.h"

using namespace std;

class Item {
public:
    explicit Item(string content);
    explicit Item(string content, string id);

    explicit Item(const char * str, const char * id1, const vector<Item> & items);

    [[nodiscard]] string get_content() const;
    [[nodiscard]] string get_id() const;


    bool operator==(const Item &other) const;

    [[nodiscard]] const ItemList get_sub_items() const;

    bool add_sub_item(const Item & item);

private:
    string content;
    string id;
    ItemList sub_items;
};



#endif //ITEM_H
