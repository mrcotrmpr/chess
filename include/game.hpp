#ifndef GAME_HPP
#define GAME_HPP

#include "square.hpp"

#include <memory>
#include <vector>

class game {
public:
    game();
    void start();
private:
    std::vector<square> squares;
    void init();
};

#endif // GAME_HPP
