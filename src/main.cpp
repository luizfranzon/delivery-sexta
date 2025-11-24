#include <chrono>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <windows.h>

using namespace std;

string gerarTimestampAtual();

struct No {
    int id;
    string descricao;
    string categoria;
    string dataCriacao;
    No *anterior;
    No *proximo;

    No(int novoId, const string &texto, const string &categoriaSelecionada)
        : id(novoId), descricao(texto), categoria(categoriaSelecionada),
        dataCriacao(gerarTimestampAtual()), anterior(nullptr), proximo(nullptr) {}
};

struct ListaPedidos {
    No *inicio;
    No *fim;

    ListaPedidos() : inicio(nullptr), fim(nullptr) {}
};

void inicializarLista(ListaPedidos &lista) {
    lista.inicio = nullptr;
    lista.fim = nullptr;
}

void destruirLista(ListaPedidos &lista) {
    No *atual = lista.inicio;
    while (atual != nullptr) {
        No *proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
    lista.inicio = nullptr;
    lista.fim = nullptr;
}

int adicionarPedido(ListaPedidos &lista, const string &descricao, const string &categoria) {
    static int proximoId = 1;
    No *novo = new No(proximoId++, descricao, categoria);

    if (lista.fim != nullptr) {
        lista.fim->proximo = novo;
        novo->anterior = lista.fim;
    } else {
        lista.inicio = novo;
    }

    lista.fim = novo;
    return novo->id;
}

string escolherCategoria() {
    const string categorias[] = {"Massas", "Doces", "Lanches", "Vegetiano", "Salgados"};

    while (true) {
        cout << "Escolha uma categoria:" << endl;
        for (size_t i = 0; i < size(categorias); ++i) {
            cout << i + 1 << ". " << categorias[i] << endl;
        }
        cout << "Opção: ";

        int opcao;
        cin >> opcao;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Tente novamente." << endl;
            continue;
        }

        if (opcao >= 1 && opcao <= static_cast<int>(size(categorias))) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return categorias[opcao - 1];
        }

        cout << "Opção inexistente. Tente novamente." << endl;
    }
}

void criarPedidoSimples(ListaPedidos &lista) {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Descreva o produto/pedido: ";
    string descricao;
    getline(cin, descricao);

    if (descricao.empty()) {
        cout << "Descrição vazia. Nada foi adicionado." << endl;
        return;
    }

    string categoria = escolherCategoria();

    int id = adicionarPedido(lista, descricao, categoria);
    cout << "Pedido #" << id << " adicionado ao fim da fila." << endl;
}

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

void subMenuOrdersGetChoice(ListaPedidos &lista) {
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
                criarPedidoSimples(lista);
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

void mainMenuGetChoice(ListaPedidos &lista) {
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
                subMenuOrdersGetChoice(lista);
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

int main() {
    ListaPedidos pedidos;
    inicializarLista(pedidos);

    printLogo();
    mainMenuGetChoice(pedidos);
    destruirLista(pedidos);

    return 0;
}

string gerarTimestampAtual() {
    auto agora = chrono::system_clock::now();
    time_t tempoAtual = chrono::system_clock::to_time_t(agora);
    tm horarioLocal {};
    localtime_s(&horarioLocal, &tempoAtual);

    ostringstream oss;
    oss << put_time(&horarioLocal, "%d/%m/%Y %H:%M:%S");
    return oss.str();
}
