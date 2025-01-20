
#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
public:
    explicit Item(string name);
    [[nodiscard]] string get_name() const;
private:
    string name;
};



#endif //ITEM_H
