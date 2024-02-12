#include "game.hpp"
#include <iostream>
#include "pieces/pawn.hpp";
#include "renderer.hpp"

game::game() {
    init();
}

void game::init() {
    squares.reserve(64);

    // Place white pieces
    squares.emplace_back(0, 0); // White rook
    squares.emplace_back(1, 0); // White knight
    squares.emplace_back(2, 0); // White bishop
    squares.emplace_back(3, 0); // White queen
    squares.emplace_back(4, 0); // White king
    squares.emplace_back(5, 0); // White bishop
    squares.emplace_back(6, 0); // White knight
    squares.emplace_back(7, 0); // White rook

    // White pawns
    for (int i = 0; i < 8; ++i) {
        squares.emplace_back(i, 1);
        auto p = std::make_shared<Pawn>();
        squares[i+8].set_piece(p);
    }

    // Add the middle squares
    for (int i = 2; i < 6; ++i) {
        for (int j = 0; j < 8; ++j) {
            squares.emplace_back(j, i);
        }
    }

    // Place black pieces
    squares.emplace_back(0, 7); // Black rook
    squares.emplace_back(1, 7); // Black knight
    squares.emplace_back(2, 7); // Black bishop
    squares.emplace_back(3, 7); // Black queen
    squares.emplace_back(4, 7); // Black king
    squares.emplace_back(5, 7); // Black bishop
    squares.emplace_back(6, 7); // Black knight
    squares.emplace_back(7, 7); // Black rook

    // Black pawns
    for (int i = 0; i < 8; ++i) {
        squares.emplace_back(i, 6);
        auto p = std::make_shared<Pawn>();
        squares[(56 + i)].set_piece(p);
    }
}

void game::start() {

    renderer::instance().create_window("Title", 800, 800);
    renderer::instance().draw_board(squares);

    bool quit = false;
    while (!quit) {
        renderer::instance().render_present();
        quit = !renderer::instance().handle_events();
    }
}
