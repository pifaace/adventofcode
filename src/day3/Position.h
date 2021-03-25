#include <string>
#include <vector>

#ifndef ADVENTOFCODE_POSITION_H
#define ADVENTOFCODE_POSITION_H

class Position {
public:
    using position_pair = std::pair<int, int>;
    int get_x() const;
    int get_y() const;
    void set_x(int);
    void set_y(int);
    void add_visited_coordinates(const std::pair<int, int> &);
    bool is_visited(const position_pair &);
    std::pair<int, int> actual_position();

private:
    int x = 0;
    int y = 0;
    std::vector<position_pair> visited_coordinates = {position_pair (0, 0)};
};

#endif //ADVENTOFCODE_POSITION_H
