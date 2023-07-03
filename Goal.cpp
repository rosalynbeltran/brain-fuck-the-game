#include "Goal.h"
#include <iostream>

namespace Game {
    bool Goal::interactuar(Jugador &player) {
        if (player.money >= 100) {
            player.money = 1337;
            return true;
        }
        std::cout << "La victoria requiere 100 monedas de oro." << "\n\n";
        return false;
    }
    Goal::Goal(WORD color, char symbol) {
        this -> color = color;
        this -> symbol = symbol;
    }
} // Game