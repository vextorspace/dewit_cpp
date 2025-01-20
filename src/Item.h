
#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item {
public:
    explicit Item(string content);
    [[nodiscard]] string get_content() const;
private:
    string content;
};



#endif //ITEM_H
