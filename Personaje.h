#ifndef C_PERSONAJE_H
#define C_PERSONAJE_H

#include "Entidad.h"

namespace Game {

    class Personaje : public Entidad {
    private:
        Stats stats{};
        short int reward;
    public:
        Personaje(WORD, char, std::string, Stats, short int);

        Personaje();

        ~Personaje();

        bool interactuar(Jugador &player);
    };

} // Game

#endif //C_PERSONAJE_H
