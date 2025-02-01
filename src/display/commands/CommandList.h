
#ifndef COMMANDLIST_H
#define COMMANDLIST_H

#include "Command.h"

#include <vector>
#include <memory>

class CommandList {
public:
  CommandList();
  ~CommandList();
  [[nodiscard]] size_t size() const;

private:
  std::vector<std::unique_ptr<Command>> commands;
};



#endif //COMMANDLIST_H
