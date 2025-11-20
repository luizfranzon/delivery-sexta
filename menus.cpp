#include <iostream>
#include <windows.h>
#include "menus.h"

using namespace std;

void printLogo() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    cout << endl;
    cout << "░██     ░██            ░██░███     ░███                       " << endl;
    cout << "░██     ░██               ░████   ░████                       " << endl;
    cout << "░██     ░██ ░████████  ░██░██░██ ░██░██  ░██████   ░██    ░██ " << endl;
    cout << "░██     ░██ ░██    ░██ ░██░██ ░████ ░██       ░██   ░██  ░██  " << endl;
    cout << "░██     ░██ ░██    ░██ ░██░██  ░██  ░██  ░███████    ░█████   " << endl;
    cout << " ░██   ░██  ░██    ░██ ░██░██       ░██ ░██   ░██   ░██  ░██  " << endl;
    cout << "  ░██████   ░██    ░██ ░██░██       ░██  ░█████░██ ░██    ░██ " << endl;
    cout << endl;
}

void presentMainMenu() {
    cout << "-----------==@==-----------" << endl;
    cout << "- 1. Pedidos" << endl;
    cout << "- 2. Estatisticas" << endl;
    cout << "- 3. Exportar dados (CSV)" << endl;
    cout << endl;
    cout << "- 0. Sair" << endl;
    cout << "-----------==@==-----------" << endl;
}