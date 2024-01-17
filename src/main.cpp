#include "game.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    std::unique_ptr<game> chess = std::make_unique<game>();
    chess->start();
    return 0;
}
