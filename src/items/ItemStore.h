
#ifndef ITEMSTORE_H
#define ITEMSTORE_H

#include "Item.h"

class ItemStore {
public:
    ItemStore();
    const Item *get_root() const;
    const Item *get_selected_item() const;
private:
    const Item root;
};



#endif //ITEMSTORE_H
