#ifndef C_GOAL_H
#define C_GOAL_H

#include "Entidad.h"

namespace Game {

    class Goal: public Entidad {
    public:
        Goal(WORD, char);
        bool interactuar(Jugador &player) override;
    };

} // Game

#endif //C_GOAL_H
