
#include "DisplayListSpy.h"

void DisplayListSpy::select_item(const Item *item) {
  if(item == nullptr) {
    this->item_selected = std::nullopt;
  } else {
    this->item_selected = item;
  }
  DisplayList::select_item(item);
}

[[nodiscard]] std::optional<const Item *> DisplayListSpy::spy_selected_item() const {
  return item_selected;
}
