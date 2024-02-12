#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SDL.h>
#include <vector>
#include "square.hpp"

class renderer {
public:
    static renderer& instance() {
        static renderer instance;
        return instance;
    }

    renderer(const renderer&) = delete;
    renderer& operator=(const renderer&) = delete;

    // Member functions
    void create_window(const char* title, int width, int height);
    void draw_board(const std::vector<square>& squares);
    void draw(const std::string path);
    bool handle_events();
    void render_present();

private:
    renderer();
    ~renderer();
    SDL_Window* window;
    SDL_Renderer* sdl_renderer;
    static constexpr int SQUARE_SIZE = 100;

    void init_sdl();
    void close_sdl();
};

#endif // RENDERER_HPP
