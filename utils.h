#pragma once

#include <windows.h>

void clearScreen() {
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;
    DWORD written;

    GetConsoleScreenBufferInfo(console, &screen);
    FillConsoleOutputCharacterA(
            console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &written
    );
    SetConsoleCursorPosition(console, topLeft);
}

void filler(char c) {
    COORD topLeft = {0, 0};
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen;

    GetConsoleScreenBufferInfo(console, &screen);

    DWORD size = (screen.dwSize.X * screen.dwSize.Y);

    SetConsoleCursorPosition(console, topLeft);

    for (int i = 0; i < size; i++) {
        printf("%c", c);
    }

    FillConsoleOutputAttribute(
            console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
            screen.dwSize.X * screen.dwSize.Y, topLeft, &size
    );
}

void loadScene() {
//    filler('*');
//    filler(' ');
    clearScreen();
}

char input() {
    std::cout << "\n" << "Que opcion desea? ";

    char a;
    std::cin >> a;

    {
        std::string buf;
        std::getline(std::cin, buf);
    }

    return a;
}