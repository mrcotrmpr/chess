#include "square.hpp"

square::square(int x, int y) : x(x), y(y), piece(nullptr) {}

int square::get_x() const {
	return x;
}

int square::get_y() const {
	return y;
}
