
#include "Item.h"

Item::Item(string name) : name(std::move(name)){
}

string Item::get_name() const {
    return name;
}
