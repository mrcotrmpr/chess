#include "renderer.hpp"
#include <iostream>

renderer::renderer() : window(nullptr), sdl_renderer(nullptr) {
    init_sdl();
}

renderer::~renderer() {
    close_sdl();
}

void renderer::init_sdl() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        exit(1);
    }
}

void renderer::create_window(const char* title, int width, int height) {
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    sdl_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void renderer::draw_board(const std::vector<square>& squares) {
    for (const auto& square : squares) {
        int x = square.get_x();
        int y = square.get_y();

        if ((x + y) % 2 == 0) {
            SDL_SetRenderDrawColor(sdl_renderer, 255, 255, 255, 255);
        }
        else {
            SDL_SetRenderDrawColor(sdl_renderer, 0, 0, 0, 255);
        }

        if (square.get_piece() != nullptr) {
            SDL_SetRenderDrawColor(sdl_renderer, 255, 0, 0, 255);
        }

        SDL_Rect rect = { x * SQUARE_SIZE, y * SQUARE_SIZE, SQUARE_SIZE, SQUARE_SIZE };
        SDL_RenderFillRect(sdl_renderer, &rect);
    }
}

bool renderer::handle_events() {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            return false;
        }
        else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
            int row = y / SQUARE_SIZE;
            int col = x / SQUARE_SIZE;
            std::cout << "Square clicked: (" << col << ", " << row << ")" << std::endl;
        }
    }
    return true;
}

void renderer::render_present() {
    SDL_RenderPresent(sdl_renderer);
}

void renderer::close_sdl() {
    if (sdl_renderer) {
        SDL_DestroyRenderer(sdl_renderer);
    }
    if (window) {
        SDL_DestroyWindow(window);
    }
    SDL_Quit();
}
