
#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
public:
    Item() = delete;
    Item(const string content);
    Item(const string content, const string id);

    void set_content(const string new_content);
    [[nodiscard]] const string get_content() const;
    [[nodiscard]] const string get_id() const;

private:
    string content;
    const string id;
};



#endif //ITEM_H
