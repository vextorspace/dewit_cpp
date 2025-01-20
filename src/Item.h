
#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
public:
    explicit Item(string content);
    [[nodiscard]] string get_content() const;

    [[nodiscard]] string get_id() const;

private:
    string content;
    string id;
};



#endif //ITEM_H
