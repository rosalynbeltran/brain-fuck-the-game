#ifndef C_ENTIDAD_H

#include "Mapeable.h"
#include "Jugador.h"

namespace Game{
    class Entidad : public Mapeable {
        public:
            std::string nombre;

            virtual bool interactuar(Jugador &) = 0;
    };
}

#define C_ENTIDAD_H

#endif //C_ENTIDAD_H
