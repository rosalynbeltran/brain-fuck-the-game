#include<iostream>
#include <memory>
#include "Game.h"
#include "utils.h"
#include "EntidadVacia.h"

namespace Game {
    void Game::frame() {
        switch (status) {
            case Status::mainMenu: {
                std::cout << "========================================" << "\n";
                std::cout << "|            Menu Principal            |" << "\n";
                std::cout << "|                                      |" << "\n";
                std::cout << "|  1. Nueva partida                    |" << "\n";
                std::cout << "|                                      |" << "\n";
                std::cout << "|  2. Cargar partida                   |" << "\n";
                std::cout << "|                                      |" << "\n";
                std::cout << "|  3. Salir                            |" << "\n";
                std::cout << "========================================" << "\n";

                char a = input();

                if (a == '1') {
                    status = Status::game;
                    std::cout << "A sus ordenes, preparese para su aventura..." << "\n\n";
                    jugador = Jugador::create();
                    mapa = Mapa{};
                } else if (a == '2') {
                    status = Status::game;
                    load();
                    jugador = Jugador::create();
                    mapa = Mapa{};
                } else if (a == '3') {
                    status = Status::exit;
                    std::cout << "Gracias por jugar" << "\n\n";
                } else {
                    std::cout << "No esta dentro de las opciones" << "\n\n";
                }
            }
                break;
            case Status::game: {
                if(jugador.stats.constitution <= 0) {
                    status = Status::mainMenu;
                    std::cout << "=========================================" << "\n";
                    std::cout << "| Tristemente, tu viaje llega a su fin, |" << "\n";
                    std::cout << "|                                       |" << "\n";
                    std::cout << "|       pero vuelve a intentarlo,       |" << "\n";
                    std::cout << "|                                       |" << "\n";
                    std::cout << "|         mantente determinado!         |" << "\n";
                    std::cout << "=========================================" << "\n";
                    break;
                }

                mapa.show(jugador);
                jugador.show_stats();

                char a = input();

                if (a == 'w') {
                    if(jugador.pos_y > 0) {
                        jugador.pos_y -= 1;
                        mapa.entorno[jugador.pos_y][jugador.pos_x].afectar_al_jugador(jugador);
                    }
                } else if (a == 'a') {
                    if(jugador.pos_x > 0) {
                        jugador.pos_x -= 1;
                        mapa.entorno[jugador.pos_y][jugador.pos_x].afectar_al_jugador(jugador);
                    }
                } else if (a == 's') {
                    if(jugador.pos_y < 9) {
                        jugador.pos_y += 1;
                        mapa.entorno[jugador.pos_y][jugador.pos_x].afectar_al_jugador(jugador);
                    }
                } else if (a == 'd') {
                    if(jugador.pos_x < 9) {
                        jugador.pos_x += 1;
                        mapa.entorno[jugador.pos_y][jugador.pos_x].afectar_al_jugador(jugador);
                    }
                } else if (a == 'x') {
                    mapa.entorno[jugador.pos_y][jugador.pos_x].afectar_al_jugador(jugador);
                } else if (a == 'f') {
                    bool del = mapa.entidad[jugador.pos_y][jugador.pos_x] -> interactuar(jugador);
                    if (del) {
                        mapa.entidad[jugador.pos_y][jugador.pos_x] = std::make_unique<EntidadVacia>();
                    }
                    if (jugador.money >= 1337) {
                        status = Status::exit;
                        loadScene();
                        std::cout << "Este es el final de tu aventura, felicidades, lo has logrado!" << "\n";
                    }
                } else if (a == 'm') {
                    status = Status::gameMenu;
                    std::cout << "Abriendo menu de partida..." << "\n\n";
                } else {
                    std::cout << "No esta dentro de las opciones" << "\n\n";
                }

            }
                break;
            case Status::gameMenu: {
                std::cout << "========================================" << "\n";
                std::cout << "|                 Menu                 |" << "\n";
                std::cout << "|                                      |" << "\n";
                std::cout << "|  1. Reanudar partida                 |" << "\n";
                std::cout << "|                                      |" << "\n";
                std::cout << "|  2. Guardar partida                  |" << "\n";
                std::cout << "|                                      |" << "\n";
                std::cout << "|  3. Salir al menu principal          |" << "\n";
                std::cout << "========================================" << "\n";

                char a = input();

                if (a == '1') {
                    status = Status::game;
                    std::cout << "Reanudar partida..." << "\n\n";
                } else if (a == '2') {
                    save();
                } else if (a == '3') {
                    status = Status::mainMenu;
                    std::cout << "Volviendo al menu principal..." << "\n\n";
                } else {
                    std::cout << "No esta dentro de las opciones" << "\n\n";
                }
            }
                break;
            default:
                return;
        }
    }
    void Game::save() {
        std::cout << "Ahora mismo esto no hace nada" << "\n\n";
    }

    void Game::load() {
        std::cout << "Ahora mismo esto no hace nada" << "\n\n";
    }
} // namespace Game