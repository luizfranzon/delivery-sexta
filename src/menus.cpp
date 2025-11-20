#include <iostream>
#include <sstream>
#include <string>
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

MainMenuChoices mainMenuGetChoice() {
    while (true) {
        presentMainMenu();

        
        cout << "Escolha uma opção: ";

        string line;
        if (!getline(cin, line)) {
            return QUIT;
        }

        stringstream ss(line);
        int choice;
        if (!(ss >> choice) || !(ss >> ws).eof() || line.empty()) {
            cout << "Entrada inválida. Digite um número válido." << endl;
            continue;
        }

        const bool isKnownOption =
                choice == QUIT || choice == ORDERS ||
                choice == STATISTICS || choice == EXPORT_TO_CSV;
        if (isKnownOption) {
            return static_cast<MainMenuChoices>(choice);
        }

        cout << "Opção inexistente. Escolha novamente." << endl;
    }
}