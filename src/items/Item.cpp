
#include "Item.h"

#include "UuidGenerator.h"

Item::Item(string content)
    : content(std::move(content))
      , id(UuidGenerator::generate()) {
}