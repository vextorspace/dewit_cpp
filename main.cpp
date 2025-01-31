#include <iostream>

#include "display/ConsoleInput.h"
#include "display/ConsoleOutput.h"
#include "display/DisplayList.h"
#include "display/Menu.h"
#include "items/ItemStore.h"

int main() {
    std::cout << "Dew It Now:" << std::endl;
    auto store = ItemStore();
    auto list = DisplayList(&store);
    auto output = ConsoleOutput();
    auto input = ConsoleInput();

    auto menu = Menu(&store, &list, &output, &input);

    while (true) {
        menu.print();
        auto selection = menu.get_user_selection();
    }

    return -1;
}
