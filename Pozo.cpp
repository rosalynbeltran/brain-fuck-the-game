#include "Pozo.h"
#include "utils.h"
#include <iostream>

namespace Game {
    bool Pozo::interactuar(Jugador &player) {
        loadScene();

        std::cout << "Ves un pozo que te recuerda a las historias de tu infancia sobre pozos de los deseos." << "\n";
        std::cout << "Podrias intentar lanzar una moneda y ver que sucede.";

        std::cin.ignore();

        loadScene();

        char in = ' ';

        while(in != '2') {
            clearScreen();

            printf("=====================================\n");
            printf("| 1. Lanzar una moneda ($1)         |\n");
            printf("|                                   |\n");
            printf("| 2. Salir de la tienda             |\n");
            printf("=====================================\n");

            std::cout << "\n";

            player.show_stats();

            in = input();

            if (in == '1') {
                if (player.money >= 1) {
                    player.money--;
                    int t = rand()%5;
                    if(t == 0) {
                        std::cout << "No pasa nada." << "\n\n";
                    } else {
                        std::cout << "Sientes un cambio en tu cuerpo." << "\n\n";
                        if (t==1) {
                            player.stats.strength++;
                        } else if (t==2) {
                            player.stats.constitution++;
                        } else if (t==3) {
                            player.stats.dexterity++;
                        } else if (t==4) {
                            player.stats.intelligence++;
                        }
                    }
                    std::cin.ignore();
                } else {
                    std::cout << "No tienes suficiente dinero para eso." << "\n\n";
                }
            } else if (in == '2') {
                std::cout << "Vuelva pronto!" << "\n\n";
            } else {
                std::cout << "No esta dentro de las opciones" << "\n\n";
            }
        }

        return false;
    }
    Pozo::Pozo(WORD color, char symbol) {
        this -> color = color;
        this -> symbol = symbol;
    }
} // Game