#ifndef C_GAME_H
#define C_GAME_H

#include "estados.h"
#include "Mapa.h"
#include "Jugador.h"

namespace Game {
    class Game {
    public:
        Status status = Status::mainMenu;
        Mapa mapa;
        Jugador jugador;

        void frame();
        void save();
        void load();
    };
} // Game

#endif //C_GAME_H
