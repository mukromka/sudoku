#pragma once
#ifndef command_h
#define command_h

class Command {
public:
    virtual void redo() = 0;
    virtual void undo() = 0;
    virtual void excecute() = 0;
};

#endif