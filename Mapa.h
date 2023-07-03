#ifndef C_MAPA_H
#define C_MAPA_H


#include <memory>
#include "Entorno.h"
#include "Entidad.h"
#include "Jugador.h"

namespace Game {

    class Mapa {
    public:
        Entorno entorno[10][10];
        std::unique_ptr<Entidad> entidad[10][10];

        Mapa();

        void show(Jugador &player);
    };

} // Game

#endif //C_MAPA_H
