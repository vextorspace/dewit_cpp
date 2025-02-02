
#ifndef COMMANDSPY_H
#define COMMANDSPY_H

#include "display/commands/Command.h"
#include "Spy.h"

class CommandSpy : public Command {
public:
    CommandSpy(std::string name, Spy *spy) : Command(name), spy(spy) {};
    void execute() override;

private:
    Spy *spy;
};



#endif //COMMANDSPY_H
