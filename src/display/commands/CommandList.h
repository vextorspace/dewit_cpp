
#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include "Command.h"

#include <vector>
#include <memory>

#include "AddItem.h"

class CommandList {
public:
  CommandList();
  ~CommandList();
  [[nodiscard]] size_t size() const;

  void add(std::unique_ptr<Command> command);

  void execute(const string &command_string);

private:
  std::vector<std::unique_ptr<Command>> commands;
};



#endif //COMMANDLIST_H
