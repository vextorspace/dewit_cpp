
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>

using namespace std;

class Item {
public:
    Item() = delete;
    Item(const string content);
    Item(const string content, const string id);

    void set_content(const string new_content);
    [[nodiscard]] const string get_content() const;
    [[nodiscard]] const string get_id() const;
    [[nodiscard]] const vector<const Item *> get_items() const;

    void add_item(const Item *item);
    inline bool operator==(const Item& other) const {
        return this->id == other.id;
    }

private:
    string content;
    const string id;
    vector<const Item *> items;
};



#endif //ITEM_H
