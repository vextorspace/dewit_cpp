#include <format>
#include <gtest/gtest.h>

#include "display/commands/Command.h"
#include "display/DisplayList.h"
#include "display/Menu.h"
#include "items/ItemStore.h"
#include "display/Output.h"
#include "OutputSpy.h"
#include "InputFake.h"
#include "DisplayListSpy.h"

TEST(Menu, print_commands_writes_list) {
    auto store = ItemStore();
    auto list = DisplayList(&store);
    auto output = OutputSpy();
    auto menu = Menu(&store, &list, &output);

    menu.print_commands();

    ASSERT_EQ(output.get_output(), "Add Item\n");
}


TEST(Menu, print_items_writes_selected_item_and_numbered_children) {
    auto store = ItemStore();
    const Item* item1 = store.create("item1");
    const Item* item2 = store.create("item2");
    optional<const Item*> child1 = store.create_in("child1", item1->get_id());
    optional<const Item*> child2 = store.create_in("child2", item1->get_id());
    auto list = DisplayList(&store);
    list.select_item(item1);
    auto output = OutputSpy();
    auto menu = Menu(&store, &list, &output);

    menu.print_items();

    ASSERT_EQ(output.get_output(),
        std::format("{}\n => 0. {}\n => 1. {}\n"
            , item1->get_content()
            , child1.value()->get_content()
            , child2.value()->get_content()));
}

TEST(Menu, print_prints_items_commands) {
    auto store = ItemStore();
    const Item* item1 = store.create("item1");
    optional<const Item*> child1 = store.create_in("child1", item1->get_id());
    auto list = DisplayList(&store);
    list.select_item(item1);
    auto output = OutputSpy();
    auto menu = Menu(&store, &list, &output);

    menu.print();
    ASSERT_EQ(output.get_output(),
        std::format("{}\n => 0. {}\n\nAdd Item\n"
            , item1->get_content()
            , child1.value()->get_content()));
}

TEST(Menu, get_response_gets_input) {
    const std::string THE_RESPONSE = "SOME INPUT::\n";
    auto input = InputFake(THE_RESPONSE);
    auto menu = Menu(nullptr, nullptr, nullptr, &input);

    std::string response = menu.get_user_selection();

    ASSERT_EQ(response, THE_RESPONSE);
}

TEST(Menu, execute_delegates_to_display_list_for_numbers) {
    auto store = ItemStore();
    const Item* item1 = store.create("item1");
    auto list = DisplayListSpy(&store);
    auto menu = Menu(&store, &list, nullptr, nullptr);

    menu.execute("1");

    auto item = list.spy_selected_item();
    ASSERT_FALSE(item.has_value());

    menu.execute("0");

    item = list.spy_selected_item();
    ASSERT_TRUE(item.has_value());
    ASSERT_EQ(item.value(), item1);
}