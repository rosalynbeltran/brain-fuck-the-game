#ifndef C_EQUIPAMIENTO_H
#define C_EQUIPAMIENTO_H

#include "Entidad.h"
#include "Jugador.h"
#include "estados.h"

namespace Game {

    class Equipamiento : public Entidad {
    public:
        Stats bonus{};
        Stats requirement{};
        Equipamiento(WORD, char, std::string, Stats, Stats);
        ~Equipamiento();
        bool interactuar(Jugador &player);
    };

} // Game

#endif //C_EQUIPAMIENTO_H
