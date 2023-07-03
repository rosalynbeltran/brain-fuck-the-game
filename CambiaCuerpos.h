#ifndef C_CAMBIACUERPOS_H
#define C_CAMBIACUERPOS_H

#include "Entidad.h"

namespace Game {

    class CambiaCuerpos: public Entidad {
        public:
        CambiaCuerpos(WORD, char);
        bool interactuar(Jugador &player) override;
    };

} // Game

#endif //C_CAMBIACUERPOS_H
