#ifndef STATESTACK_HPP
#define STATESTACK_HPP

#include <stack>
#include <memory>
#include "IState.hpp"

class Game;

class StateStack {
private:
    std::stack<std::unique_ptr<IState>> stack;

public:
    void push(std::unique_ptr<IState> st, Game& g);
    void pop(Game& g);
    void replace(std::unique_ptr<IState> st, Game& g);
    IState* top();
};

#endif
