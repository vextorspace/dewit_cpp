
#include "ItemStore.h"

ItemStore::ItemStore() : root(Item("root")){
}
const Item * ItemStore::get_root() const {
    return &root;
}