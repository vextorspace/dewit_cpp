#include <iostream>

#include "display/ConsoleOutput.h"
#include "display/DisplayList.h"
#include "display/Menu.h"
#include "items/ItemStore.h"

int main() {
    std::cout << "Dew It Now:" << std::endl;
    auto store = ItemStore();
    auto list = DisplayList(&store);
    auto output = ConsoleOutput();
    auto menu = Menu(&store, &list, &output);

    menu.print();

    return 0;
}
