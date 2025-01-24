
#ifndef ITEMSTORE_H
#define ITEMSTORE_H

#include "Item.h"

class ItemStore {
public:
    ItemStore();
    const Item *get_root() const;
private:
    const Item root;
};



#endif //ITEMSTORE_H
