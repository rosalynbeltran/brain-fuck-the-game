#include<iostream>
#include "Game.cpp"
#include "Mapeable.cpp"
#include "EntidadVacia.cpp"
#include "Entorno.cpp"
#include "Equipamiento.cpp"
#include "Jugador.cpp"
#include "Personaje.cpp"
#include "Goal.cpp"
#include "CambiaCuerpos.cpp"
#include "Pozo.cpp"
#include "Mapa.cpp"
#include "utils.h"

int main() {
     Game::Game game{};

     std::cout << "Para mejor disfrute del juego, maximice su consola.";

     std::cin.ignore();

     Game::Status prevState = Game::Status::start;

     while(game.status != Game::Status::exit) {
         if(prevState == game.status) {
             clearScreen();
         }
         else {
             loadScene();
         }
         prevState = game.status;
         game.frame();
         std::cin.ignore();
     }
}