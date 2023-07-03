#ifndef C_MAPEABLE_H
#define C_MAPEABLE_H

#include "windows.h"

namespace Game {
    class Mapeable {
    protected:
        WORD color;
    public:
        char symbol;
        void show() const;
    };
}


#endif //C_MAPEABLE_H
