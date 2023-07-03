#include "CambiaCuerpos.h"
#include "utils.h"
#include <iostream>

namespace Game {
    bool CambiaCuerpos::interactuar(Jugador &player) {
        if ((player.stats.intelligence + player.bonus.intelligence >= 10) ||
            (player.stats.dexterity + player.bonus.dexterity >= 10)) {
            loadScene();
            std::cout << " Mientras te adentras en lo profundo del bosque, encuentras un claro iluminado por la luna."
                      << "\n";
            std::cout << " En el centro se ve el tronco cortado de un arbol, y encima ves un pequenyo animal. Cuando "
                      << "\n";
            std::cout << " te acercas vez que es un erizo, pero sus ojos tienen un brillo extranyo. Despues de un    "
                      << "\n";
            std::cout << " tiempo mirandolo, escuchas una voz en tu mente, \"Por el precio correcto puedo cambiar tu "
                      << "\n";
            std::cout << " cuerpo, hacerte mas fuerte, mas resistente... pero claro... por el precio correcto\". Tu  "
                      << "\n";
            std::cout << " por supuesto, decides que esto es una buena idea, y preguntas sus precios.                "
                      << "\n";
            std::cin.ignore();

            loadScene();

            char in = ' ';

            while(in != '5') {
                clearScreen();

                printf("=========================================\n");
                printf("| 1. Fuerza ($%d)                        |\n", (player.stats.strength / 5 + 1));
                printf("|                                       |\n");
                printf("| 2. Constitucion ($%d)                  |\n", 1);
                printf("|                                       |\n");
                printf("| 3. Destreza ($%d)                      |\n", (player.stats.dexterity / 10 + 1));
                printf("|                                       |\n");
                printf("| 4. Inteligencia ($%d)                  |\n", (player.stats.intelligence / 10 + 1));
                printf("|                                       |\n");
                printf("| 5. Salir de la tienda                 |\n");
                printf("=========================================\n");

                std::cout << "\n";

                player.show_stats();

                in = input();

                if (in == '1') {
                    if (player.money >= (player.stats.strength / 5 + 1)) {
                        std::cout << "Te vuelves mas fuerte!" << "\n\n";
                        player.money -= (player.stats.strength / 5 + 1);
                        player.stats.strength++;
                    } else {
                        std::cout << "No tienes suficiente dinero para eso." << "\n\n";
                    }
                } else if (in == '2') {
                    if (player.money >= 1) {
                        std::cout << "Te vuelves mas resistente!" << "\n\n";
                        player.money--;
                        player.stats.constitution++;
                    } else {
                        std::cout << "No tienes suficiente dinero para eso." << "\n\n";
                    }
                } else if (in == '3') {
                    if (player.money >= (player.stats.dexterity / 10 + 1)) {
                        std::cout << "Tu destreza aumenta!" << "\n\n";
                        player.money -= (player.stats.dexterity / 10 + 1);
                        player.stats.dexterity++;
                    } else {
                        std::cout << "No tienes suficiente dinero para eso." << "\n\n";
                    }
                } else if (in == '4') {
                    if (player.money >= (player.stats.intelligence / 10 + 1)) {
                        std::cout << "Tu inteligencia aumenta!" << "\n\n";
                        player.money -= (player.stats.intelligence / 10 + 1);
                        player.stats.intelligence++;
                    } else {
                        std::cout << "No tienes suficiente dinero para eso." << "\n\n";
                    }
                } else if (in == '5') {
                    std::cout << "Vuelva pronto!" << "\n\n";
                } else {
                    std::cout << "No esta dentro de las opciones" << "\n\n";
                }
            }

            return false;
        } else {
            std::cout << "Parece que algo estaba aqui, pero se fue." << "\n";
            return true;
        }
    }

    CambiaCuerpos::CambiaCuerpos(WORD color, char symbol) {
        this->color = color;
        this->symbol = symbol;
        this->nombre = "???";
    }
} // Game