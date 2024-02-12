#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <iostream>
#include "pieces/piece.hpp"

class square {
public:
    square(int x, int y);
    int get_x() const;
    int get_y() const;
    void set_piece(std::shared_ptr<Piece> new_piece) { piece = new_piece; }
    std::shared_ptr<Piece> get_piece() const { return piece; }
private:
    int x, y;
    std::shared_ptr<Piece> piece;
};

#endif // SQUARE_HPP
