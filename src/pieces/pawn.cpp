#include "pieces/pawn.hpp"
#include "renderer.hpp"
#include <iostream>


void Pawn::move()
{
	std::cout << "move() called" << std::endl;
}

void Pawn::draw()
{
	renderer::instance().draw("pawn");
}
