#include "StateStack.hpp"
#include "../Engine/Game.hpp"

void StateStack::push(std::unique_ptr<IState> st, Game& g) {
    stack.push(std::move(st));
    stack.top()->onEnter(g);
}

void StateStack::pop(Game& g) {
    if (!stack.empty()) {
        stack.top()->onExit(g);
        stack.pop();
    }
}

void StateStack::replace(std::unique_ptr<IState> st, Game& g) {
    pop(g);
    push(std::move(st), g);
}

IState* StateStack::top() {
    return stack.empty() ? nullptr : stack.top().get();
}
