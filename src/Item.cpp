
#include "Item.h"

Item::Item(string content) : content(std::move(content)){
}

string Item::get_content() const {
    return content;
}
