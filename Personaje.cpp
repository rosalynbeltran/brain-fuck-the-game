#include "Personaje.h"
#include <iostream>

namespace Game {
    bool Personaje::interactuar(Jugador &player) {
        std::cout << "Enfrentandote a: " << nombre << "\n";
        printf("fuerza: %d, constitucion: %d, destreza: %d, inteligencia: %d\n\n",
               stats.strength, stats.constitution, stats.dexterity, stats.intelligence);
        while(stats.constitution > 0 && player.stats.constitution > 0) {
            stats.constitution -= player.stats.strength;
            if(stats.constitution > 0) {
                player.stats.constitution -= stats.strength;
            }
        }
        if(player.stats.constitution > 0) {
            std::cout << "\n" << "Victoria!" << "\n\n";
            player.money += reward;
            return true;
        }
        return false;
    }

    Personaje::Personaje(WORD color, char c, std::string nombre, Stats stats, short int reward) {
        this->color = color;
        this->symbol = c;
        this->nombre = std::move(nombre);
        this->stats = stats;
        this->reward = reward;
    }

    Personaje::Personaje() {}

    Personaje::~Personaje() = default;

} // Game