#ifndef SQUARE_HPP
#define SQUARE_HPP

class square {
public:
    square(int x, int y);
    int get_x() const;
    int get_y() const;

private:
    int x, y;
};

#endif // SQUARE_HPP
