#ifndef C_JUGADOR_H
#define C_JUGADOR_H

#include "estados.h"
#include <string>

namespace Game {

    class Jugador{
    protected:
        Raza raza;
        Profession profession;
    public:
        std::string nombre;
        short int money;
        Stats stats;
        Stats bonus;
        short int pos_x;
        short int pos_y;

        Jugador();

        static Jugador create();

        void show_stats() const;
    };

} // Game

#endif //C_JUGADOR_H
