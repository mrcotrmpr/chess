#ifndef PIECE_HPP
#define PIECE_HPP

#include <string>

class Piece {
public:
	virtual void move() = 0;
	virtual void draw() = 0;
};

#endif // PIECE_HPP
