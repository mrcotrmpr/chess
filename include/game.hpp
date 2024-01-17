#ifndef GAME_HPP
#define GAME_HPP

#include "renderer.hpp"
#include "square.hpp"

#include <memory>
#include <vector>

class game {
public:
    game();
    void start();
private:
    std::unique_ptr<renderer> sdl_renderer;
    std::vector<square> squares;
    void init();
};

#endif // GAME_HPP
