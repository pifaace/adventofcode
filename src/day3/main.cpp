#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Position.h"

using namespace std;

void next_position(Position &position, const char &next_move) {
    switch (next_move) {
        case '^':
            position.set_y(position.get_y()+1);
            break;
        case 'v':
            position.set_y(position.get_y()-1);
            break;
        case '<':
            position.set_x(position.get_x()-1);
            break;
        case '>':
            position.set_x(position.get_x()+1);
            break;
        default:
            cout << "invalid move";
            break;
    }
}

int main() {
    ifstream myfile("/home/maxime/path.txt");
    string path;
    Position santa_position;
    Position robo_position;
    int presents = 1;
    int i = 0;

    getline(myfile, path);

    for (const auto &next_move : path) {
        if (i % 2 == 0) {
            next_position(santa_position, next_move);
            if (!santa_position.is_visited(santa_position.actual_position())) {
                santa_position.add_visited_coordinates(santa_position.actual_position());
                robo_position.add_visited_coordinates(santa_position.actual_position());
                presents++;
            }
        } else {
            next_position(robo_position, next_move);
            if (!robo_position.is_visited(robo_position.actual_position())) {
                robo_position.add_visited_coordinates(robo_position.actual_position());
                santa_position.add_visited_coordinates(robo_position.actual_position());
                presents++;
            }
        }
        ++i;
    }

    cout << presents;

    return 0;
}
