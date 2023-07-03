#ifndef C_ENTORNO_H
#define C_ENTORNO_H

#include "Mapeable.h"
#include "estados.h"
#include "Jugador.h"

namespace Game {

class Entorno : public Mapeable {
        Stats price;

    public:
        Entorno(const Stats &, char, WORD);

        Entorno();

        void afectar_al_jugador(Jugador &player);
    };

} // Game

#endif //C_ENTORNO_H
