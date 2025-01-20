
#include "Item.h"
#include "UuidGenerator.h"

Item::Item(string content)
    : Item(std::move(content), UuidGenerator().generate()) {
}

Item::Item(string content, string id)
    : content(std::move(content))
    , id(std::move(id)) {
}

string Item::get_content() const {
    return content;
}

string Item::get_id() const {
    return id;
}
