#ifndef C_ESTADOS_H
#define C_ESTADOS_H

namespace Game {
    enum Status {
        start, mainMenu, game, gameMenu, exit
    };

    enum Raza {
        human = 1, dwarf, elven, half_orc, half_elf, gnome
    };

    enum Profession {
        warrior = 1, mage, ranger, druid, priest, paladin
    };

    struct Stats {
        short int strength;
        short int constitution;
        short int dexterity;
        short int intelligence;
    };
}

#endif //C_ESTADOS_H
