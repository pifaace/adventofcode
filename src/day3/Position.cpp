#include "Position.h"

int Position::get_x() const {
    return x;
}

int Position::get_y() const {
    return y;
}

void Position::set_x(int new_x) {
    x = new_x;
}

void Position::set_y(int new_y) {
    y = new_y;
}

void Position::add_visited_coordinates(const std::pair<int, int> &value) {
    visited_coordinates.push_back(value);
}

bool Position::is_visited(const std::pair<int, int> &value) {
    for (auto it = visited_coordinates.begin() ; it != visited_coordinates.end() ; ++it) {
        if (value.first == it->first && value.second == it->second) {
            return true;
        }
    }

    return false;
}

std::pair<int, int> Position::actual_position() {
    return std::pair<int, int> (x, y);
}
