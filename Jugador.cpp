#include "Jugador.h"
#include "utils.h"
#include "estados.h"
#include <iostream>

namespace Game {
    Jugador Jugador::create() {
        clearScreen();

        Jugador nuevo;

        std::cout << "Como te llamas? " << "\n\n";
        std::cin >> nuevo.nombre;

        std::cout << "Elija su raza " << "\n\n";
        std::cout << "==============================" << "\n";
        std::cout << "|  1. Humano   4. Semi-orco  |" << "\n";
        std::cout << "|                            |" << "\n";
        std::cout << "|  2. Enano    5. Semi-elfo  |" << "\n";
        std::cout << "|                            |" << "\n";
        std::cout << "|  3. Elfo     6. Gnomo      |" << "\n";
        std::cout << "==============================" << "\n";

        int raza=-1;
        while (raza <= 0 || raza > 6) {
            std::cin >> raza;
            if (raza <= 0 || raza > 6) {
                std::cout << "No esta dentro de las opciones" << "\n\n";
            }
        }
        nuevo.raza = static_cast<Raza>(raza);

        std::cout << "Elija su profesion " << "\n\n";
        std::cout << "==============================" << "\n";
        std::cout << "|  1. Guerrero 4. Druida     |" << "\n";
        std::cout << "|                            |" << "\n";
        std::cout << "|  2. Mago     5. Sacerdote  |" << "\n";
        std::cout << "|                            |" << "\n";
        std::cout << "|  3. Arquero  6. Paladin    |" << "\n";
        std::cout << "==============================" << "\n";

        int profession=-1;
        while (profession <= 0 || profession > 6) {
            std::cin >> profession;
            if (profession <= 0 || profession > 6) {
                std::cout << "No esta dentro de las opciones" << "\n\n";
            }
        }
        nuevo.profession = static_cast<Profession>(profession);

        switch (nuevo.profession) {
            case Profession::warrior:
                nuevo.stats = {10, 10, 5, 5};
            case Profession::mage:
                nuevo.stats = {5, 7, 7, 11};
            case Profession::priest:
                nuevo.stats = {7, 9, 3, 11};
            case Profession::paladin:
                nuevo.stats = {12, 12, 3, 3};
            case Profession::ranger:
                nuevo.stats = {8, 4, 11, 7};
            case Profession::druid:
                nuevo.stats = {8, 10, 5, 7};
        }

        switch (nuevo.raza) {
            case Raza::human:
                nuevo.stats.strength += 1;
                nuevo.stats.constitution += 1;
                nuevo.stats.dexterity += 1;
                nuevo.stats.intelligence += 1;
                break;
            case Raza::elven:
                nuevo.stats.dexterity += 2;
                nuevo.stats.intelligence += 1;
                break;
            case Raza::dwarf:
                nuevo.stats.strength += 1;
                nuevo.stats.constitution += 2;
                break;
            case Raza::gnome:
                nuevo.stats.dexterity += 1;
                nuevo.stats.intelligence += 2;
                break;
            case Raza::half_elf:
                nuevo.stats.strength += 1;
                nuevo.stats.intelligence += 2;
                break;
            case Raza::half_orc:
                nuevo.stats.strength += 2;
                nuevo.stats.constitution += 1;
                break;
            default:
                break;
        }

        return nuevo;
    }

    Jugador::Jugador() {
        pos_x = 0;
        pos_y = 0;
        bonus = Stats{0, 0, 0, 1};
        money = 10;
    }

    void Jugador::show_stats() const {
        std::cout << "Dinero: " << money << " ";
        std::cout << "Fuerza: " << stats.strength << "+" << bonus.strength << " ";
        std::cout << "Constitucion: " << stats.constitution << "+" << bonus.constitution << " ";
        std::cout << "Destreza: " << stats.dexterity << "+" << bonus.dexterity << " ";
        std::cout << "Inteligencia: " << stats.intelligence << "+" << bonus.intelligence << "\n";
    }
} // Game