#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif // GAMESTATE_HPPE_H