
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <vector>
#include <gtest/gtest.h>

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
    void remove_item(const string &id);

    inline bool operator==(const Item& other) const {
        return this->id == other.id;
    }

    friend void PrintTo(const Item &item, ::std::ostream *os);

    void remove_child(const Item * child);

    [[nodiscard]] bool has_child(const string & child_id) const;

private:
    string content;
    const string id;
    vector<const Item *> items;
};



#endif //ITEM_H
