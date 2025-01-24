
#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
public:
    Item() = delete;
    Item(const string content);

private:
    string content;
    string id;
};



#endif //ITEM_H
