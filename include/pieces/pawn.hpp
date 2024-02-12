#ifndef PAWN_HPP
#define PAWN_HPP

#include "piece.hpp"

class Pawn : public Piece {
public:
    void move() override;
    void draw() override;
};

#endif // PAWN_HPP
