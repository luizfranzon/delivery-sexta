#include <iostream>
#include <limits>
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

void subMenuOrdersGetChoice() {
    while (true) {
        cout << "-------==@==-------" << endl;
        cout << "- 1. Criar pedido" << endl;
        cout << "- 2. Ver pedidos" << endl;
        cout << "- 4. Remover pedido" << endl;
        cout << "- 5. Enviar para o fim da fila" << endl;
        cout << "- 6. Enviar para o início da fila" << endl;
        cout << endl;
        cout << "- 0. Voltar ao menu principal" << endl;
        cout << "-------==@==-------" << endl;

        cout << "Escolha uma opção: ";

        int choice;
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Escolha novamente." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 0:
                return;
            default:
                cout << "Opção inexistente. Escolha novamente." << endl;
                break;
        }
    }
}

void mainMenuGetChoice() {
    while (true) {
        cout << "-----------==@==-----------" << endl;
        cout << "- 1. Pedidos" << endl;
        cout << "- 2. Estatisticas" << endl;
        cout << "- 3. Exportar dados (CSV)" << endl;
        cout << endl;
        cout << "- 0. Sair" << endl;
        cout << "-----------==@==-----------" << endl;

        cout << "Escolha uma opção: ";

        int choice;
        cin >> choice;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Escolha novamente." << endl;
            continue;
        }

        switch (choice) {
            case 1:
                subMenuOrdersGetChoice();
                break;
            case 2:
                cout << "Estatísticas ainda não disponíveis." << endl;
                break;
            case 3:
                cout << "Exportação ainda não disponível." << endl;
                break;
            case 0:
                return;
            default:
                cout << "Opção inexistente. Escolha novamente." << endl;
                break;
        }
    }
}
