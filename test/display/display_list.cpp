#include <gtest/gtest.h>

#include "display/DisplayList.h"
#include "items/ItemStore.h"

TEST(DisplayList, has_store) {
    auto store = ItemStore();
    auto list = DisplayList(&store);

    ASSERT_EQ(store.get_root(), list.get_root());
}

TEST(DisplayList, selected_item_defaults_to_root) {
    auto store = ItemStore();
    auto list = DisplayList(&store);
    ASSERT_EQ(list.get_selected_item(), store.get_root());
}

TEST(DisplayList, can_change_selected_item) {
    auto store = ItemStore();
    const Item * item = store.create("item");
    auto list = DisplayList(&store);
    ASSERT_EQ(list.get_selected_item(), store.get_root());
    list.select_item(item);
}

TEST(DisplayList, gets_current_selected_item_list) {
    auto store = ItemStore();
    const Item* item1 = store.create("item1");
    const Item* item2 = store.create("item2");
    optional<const Item*> child1 = store.create_in("child1", item1->get_id());
    optional<const Item*> child2 = store.create_in("child2", item1->get_id());

    auto list = DisplayList(&store);
    list.select_item(item1);

    std::vector<const Item *> items = list.items();

    ASSERT_EQ(items.size(), 2);
    ASSERT_EQ(items[0]->get_id(), child1.value()->get_id());
    ASSERT_EQ(items[1]->get_id(), child2.value()->get_id());
}

TEST(DisplayList, keeps_a_breadcrumb_trail_of_selected_items) {
    auto store = ItemStore();
    const Item* item1 = store.create("item1");
    const Item* item2 = store.create("item2");
    optional<const Item*> child1 = store.create_in("child1", item1->get_id());
    optional<const Item*> child2 = store.create_in("child2", item1->get_id());

    auto list = DisplayList(&store);
    list.select_item(item1);

    std::vector<const Item *> trail = list.get_breadcrumbs();

    ASSERT_EQ(trail.size(), 2);
    ASSERT_EQ(trail[0]->get_id(), store.get_root()->get_id());
    ASSERT_EQ(trail[1]->get_id(), item1->get_id());
}

TEST(DisplayList, can_pop_breadcrumb_trail) {
    auto store = ItemStore();
    const Item* item1 = store.create("item1");
    const Item* item2 = store.create("item2");
    optional<const Item*> child1 = store.create_in("child1", item1->get_id());
    optional<const Item*> child2 = store.create_in("child2", item1->get_id());

    auto list = DisplayList(&store);
    list.select_item(item1);
    list.go_back();
    list.select_item(item2);
    std::vector<const Item *> trail = list.get_breadcrumbs();

    ASSERT_EQ(trail.size(), 2);
    ASSERT_EQ(trail[0]->get_id(), store.get_root()->get_id());
    ASSERT_EQ(trail[1]->get_id(), item2->get_id());
}

TEST(DisplayList, can_request_input) {
    std::istringstream simulatedInput("hello there"); // Simulated user input
    std::streambuf* origCin = std::cin.rdbuf(); // Backup original cin
    std::cin.rdbuf(simulatedInput.rdbuf());     // Replace cin with simulated input

    auto store = ItemStore();
    auto list = DisplayList(&store);

    string text = list.get_input();

    std::cin.rdbuf(origCin);

    ASSERT_EQ(text, "hello there");
}