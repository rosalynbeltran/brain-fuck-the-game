#include "Entorno.h"
#include "Jugador.h"
#include <iostream>
#include <windows.h>

namespace Game {
    void Entorno::afectar_al_jugador(Jugador &player) {
        if((price.strength | price.constitution | price.dexterity | price.intelligence) != 0) {
            printf("El entorno te afecta y pierdes estadisticas!, fuerza: %d, constitucion: %d, destreza: %d, inteligencia: %d\n\n",
                   price.strength, price.constitution, price.dexterity, price.intelligence);
            player.stats.strength -= price.strength;
            player.stats.constitution -= price.constitution;
            player.stats.dexterity -= price.dexterity;
            player.stats.intelligence -= price.intelligence;
        }
    }

    Entorno::Entorno(const Stats &price, const char c, WORD color) {
        this->price = price;
        this->symbol = c;
        this->color = color;
    }

    Entorno::Entorno() : Mapeable() {
        this->price = Stats{0, 0, 0, 0};
        this->symbol = ' ';
    }

} // Game