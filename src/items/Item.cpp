
#include "Item.h"

#include "UuidGenerator.h"

Item::Item(const string content)
    : content(std::move(content))
      , id(UuidGenerator::generate()) {
}

Item::Item(const string content, const string id)
    : content(std::move(content))
      , id(std::move(id)) {
}

void Item::set_content(const string new_content) {
    content = new_content;
}

const string Item::get_content() const {
    return content;
}

const string Item::get_id() const {
    return id;
}