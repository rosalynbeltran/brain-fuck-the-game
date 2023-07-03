#ifndef C_ENTIDADVACIA_H
#define C_ENTIDADVACIA_H

#include "Jugador.h"
#include "Entidad.h"

namespace Game {

    class EntidadVacia: public Entidad {
    public:
        EntidadVacia();
        bool interactuar(Jugador &player) override;
    };

} // Game

#endif //C_ENTIDADVACIA_H
