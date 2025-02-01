
#ifndef DISPLAYLISTSPY_H
#define DISPLAYLISTSPY_H

#include "display/DisplayList.h"

class DisplayListSpy : public DisplayList{
public:
  explicit DisplayListSpy(ItemStore *store) : DisplayList(store) {
                                       item_selected = std::nullopt;
  };

    void select_item(const Item * item) override;
    [[nodiscard]] std::optional<const Item *> spy_selected_item() const;

private:
  std::optional<const Item *> item_selected;
};



#endif //DISPLAYLISTSPY_H
