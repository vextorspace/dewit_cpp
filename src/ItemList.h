
#ifndef ITEMLIST_H
#define ITEMLIST_H
#include <cstddef>
#include <vector>
#include <initializer_list>
class Item;

class ItemList {
public:
    ItemList() = default;
    explicit ItemList(const std::vector<Item> & items);
    explicit ItemList(const std::initializer_list<Item> items);

    [[nodiscard]] const size_t size() const;
    [[nodiscard]] const std::vector<Item> get_items() const;

    [[nodiscard]] const bool is_empty() const;

    bool add_item(const Item &item);

    [[nodiscard]] const std::vector<std::string> get_content_list() const;

    [[nodiscard]] const std::optional<Item*> find_item(const Item & item) const;

private:
    std::vector<Item> items;
};



#endif //ITEMLIST_H
