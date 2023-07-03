#include "Equipamiento.h"
#include <iostream>

namespace Game {
    bool Equipamiento::interactuar(Jugador &player) {
        if (player.stats.strength >= requirement.strength &&
            player.stats.constitution >= requirement.constitution &&
            player.stats.dexterity >= requirement.dexterity &&
            player.stats.intelligence >= requirement.intelligence
            ) {
            player.bonus = this->bonus;
            std::cout << "Has equipado: " << nombre << "\n\n";
            return true;
        } else {
            std::cout << "Faltan estadisticas para equipar: " << nombre << "\n\n";
            return false;
        }
    }

    Equipamiento::Equipamiento(WORD color, char a, std::string nombre, Stats bonus, Stats requirements) {
        this->color = color;
        this->symbol = a;
        this->nombre = std::move(nombre);
        this->bonus = bonus;
        this->requirement = requirements;
    }

    Equipamiento::~Equipamiento() = default;
} // Game