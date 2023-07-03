#ifndef C_POZO_H
#define C_POZO_H

#include "Entidad.h"

namespace Game {

    class Pozo: public Entidad{
        public:
        Pozo(WORD, char);
        bool interactuar(Jugador &player) override;
    };

} // Game

#endif //C_POZO_H
