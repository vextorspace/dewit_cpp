
#include "Item.h"

#include "UuidGenerator.h"

Item::Item(string content)
    : content(std::move(content))
      , id(UuidGenerator::generate()) {
}

const string Item::get_content() const {
    return content;
}

const string Item::get_id() const {
    return id;
}