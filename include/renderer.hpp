#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL.h>
#include <vector>
#include "square.hpp"

class renderer {
public:
    renderer();
    ~renderer();
    void create_window(const char* title, int width, int height);
    void draw_board(const std::vector<square>& squares);
    bool handle_events();
    void render_present();

private:
    SDL_Window* window;
    SDL_Renderer* sdl_renderer;
    static constexpr int SQUARE_SIZE = 100;

    void init_sdl();
    void close_sdl();
};

#endif // RENDERER_HPP
