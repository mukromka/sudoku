#ifndef invoker_h
#define invoker_h
//aas
#pragma once
#include <stack>
#include "command.h"

class Invoker {
private:
    stack <Command*> Commands;
    stack <Command*> Redo;
public:
    void pushCommand(Command& command);
    void popCommandUndo();
    void popCommandRedo();
};

void Invoker::pushCommand(Command& command) {
    Commands.push(&command);
    cout << "Command is added" << endl;
}

void Invoker::popCommandUndo() {
    if (Commands.empty() == true) {
        cout << "The stack is empty" << endl;
    }
    else {
        cout << "command popped" << endl;
        Redo.push(Commands.top());
        Commands.top()->undo();
        Commands.pop();
    }
}

void Invoker::popCommandRedo() {
    if (Redo.empty() == true) {
        cout << "The stack is empty" << endl;
    }
    else {
        cout << "command popped" << endl;
        Redo.top()->redo();
        Redo.pop();
    }
}
#endif /* invoker_h */
