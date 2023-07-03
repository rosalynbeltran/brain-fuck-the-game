#include "EntidadVacia.h"
#include "Jugador.h"
#include <iostream>

namespace Game {

    bool EntidadVacia::interactuar(Jugador &player) {
        std::cout << "No hay nada con que interactuar aqui " << player.nombre << "\n\n";
        return false;
    }

    EntidadVacia::EntidadVacia() {
        this -> color = 0;
        this -> symbol = ' ';
    }
} // Game