#ifndef ADDITEM_H
#define ADDITEM_H
#include "Command.h"
#include "display/DisplayList.h"
#include "items/ItemStore.h"


class AddItem : public Command{
public:
    AddItem() = delete;
    explicit AddItem(ItemStore *item_store, DisplayList *display_list);
    void execute() override;

private:
    ItemStore *item_store;
    DisplayList *display_list;


};



#endif //ADDITEM_H
