#include "game.hpp"

game::game() : sdl_renderer(std::make_unique<renderer>()) {
    init();
}

void game::init() {
    squares.reserve(64);
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            squares.emplace_back(j, i);
        }
    }
}

void game::start() {
    sdl_renderer->create_window("Chess", 800, 800);
    sdl_renderer->draw_board(squares);

    bool quit = false;
    while (!quit) {
        sdl_renderer->render_present();
        quit = !sdl_renderer->handle_events();
    }
}
