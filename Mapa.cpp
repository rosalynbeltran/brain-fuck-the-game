#include "Mapa.h"
#include "EntidadVacia.h"
#include "Personaje.h"
#include "Equipamiento.h"
#include "Goal.h"
#include "CambiaCuerpos.h"
#include "Pozo.h"
#include <iostream>

namespace Game {
    void Mapa::show(Jugador &player) {
        std::cout << "=========================================" << "\n";
        for (int i = 0; i < 10; i++) {
            std::cout << "|";
            for (int j = 0; j < 10; j++) {
                if (i==player.pos_y &&j==player.pos_x) {
                    std::cout << "*";
                } else {
                    std::cout << " ";
                }
                entidad[i][j] -> show();
                entorno[i][j].show();
                std::cout << "|";
            }
            std::cout << "\n";
            std::cout << "=========================================" << "\n";
        }
        std::cout << "\n";
    }

    Mapa::Mapa() {
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                this->entorno[i][j] = Entorno{};
            }
        }
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                this->entidad[i][j] = std::unique_ptr<Entidad>(new EntidadVacia{});
            }
        }
        this->entidad[8][9] = std::unique_ptr<Entidad>( new Personaje{
                FOREGROUND_RED,
                'E',
                "lobo",
                Stats{4, 2, 5, 0},
                11
        });
        this->entidad[1][3] =  std::unique_ptr<Entidad>( new Personaje{
                FOREGROUND_RED,
                'E',
                "harpia",
                Stats{4, 7, 4, 0},
                15
        });
        this->entidad[1][8] =  std::unique_ptr<Entidad>( new Personaje{
                FOREGROUND_RED,
                'E',
                "Goblins",
                Stats{5, 7, 2, 0},
                14
        });
        this->entidad[4][2] =  std::unique_ptr<Entidad>( new Personaje{
                FOREGROUND_RED,
                'E',
                "Bandidos",
                Stats{5, 10, 3, 0},
                18
        });
        this->entidad[3][6] =  std::unique_ptr<Entidad>( new Personaje{
                FOREGROUND_RED,
                'E',
                "Ciclope",
                Stats{15, 14, 7, 0},
                36
        });
        this->entidad[7][4] =  std::unique_ptr<Entidad>( new Personaje{
                FOREGROUND_RED,
                'E',
                "Gargolas",
                Stats{10, 10, 5, 0},
                25
        });
        this->entidad[9][8] =  std::unique_ptr<Entidad>( new Personaje{
                FOREGROUND_RED,
                'E',
                "Minotauro",
                Stats{25, 17, 15, 0},
                57
        });
        this->entidad[6][7] =  std::unique_ptr<Entidad>( new Personaje{
                FOREGROUND_RED,
                'E',
                "Sirena",
                Stats{4, 4, 7, 0},
                15
        });

        this->entidad[3][2] =  std::unique_ptr<Entidad>( new Equipamiento{
                FOREGROUND_RED | FOREGROUND_BLUE,
                'A',
                "Varita de fuego",
                Stats{0, 0, 12, 0},
                Stats{0, 0, 0, 12}
        });
        this->entidad[0][7] = std::unique_ptr<Entidad>( new Equipamiento{
                FOREGROUND_RED | FOREGROUND_BLUE,
                'A',
                "Arco de Apolo",
                Stats{0, 0, 2, 0},
                Stats{0, 0, 0, 0}
        });
        this->entidad[4][5] = std::unique_ptr<Entidad>( new Equipamiento{
                FOREGROUND_RED | FOREGROUND_BLUE,
                'A',
                "Baston de Davo",
                Stats{0, 0, 2, 0},
                Stats{0, 0, 0, 12}
        });
        this->entidad[7][7] = std::unique_ptr<Entidad>( new Equipamiento{
                FOREGROUND_RED | FOREGROUND_BLUE,
                'A',
                "Espada de acero",
                Stats{0, 0, 2, 0},
                Stats{0, 11, 0, 0}
        });
        this->entidad[4][7] = std::unique_ptr<Entidad>( new Equipamiento{
                FOREGROUND_RED | FOREGROUND_BLUE,

                'A',
                "Mjiolnir",
                Stats{0, 0, 5, 0},
                Stats{12, 0, 0, 0}
        });


        this->entorno[9][0] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[9][1] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[8][1] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[7][1] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[7][2] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[7][3] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[6][3] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[6][4] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[6][5] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[6][6] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[6][7] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[5][7] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[5][8] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};
        this->entorno[5][9] = Entorno{Stats{0, 1, 0, 0}, '~', FOREGROUND_BLUE};

        this->entidad[2][0] = std::unique_ptr<Pozo>( new Pozo{
            FOREGROUND_GREEN,
            '$',
        });

        this->entidad[8][8] = std::unique_ptr<CambiaCuerpos>( new CambiaCuerpos{
            FOREGROUND_GREEN,
            '$',
        });

        this->entidad[9][9] = std::unique_ptr<Goal>( new Goal{
            FOREGROUND_RED | FOREGROUND_GREEN,
            'V',
        });
    }

} // Game