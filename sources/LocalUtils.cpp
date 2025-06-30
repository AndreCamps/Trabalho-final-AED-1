#include "LocalUtils.h"
#include <iostream>
using namespace std;

bool escolherLocal(infoLocal& selecionado) {
    int total = 0;
    infoLocal* locais = Local::listarTodosLocais(total);

    if (!locais || total == 0) {
        cout << "Nenhum local encontrado.\n";
        return false;
    }

    cout << "\n== Locais Disponíveis ==\n";
    for (int i = 0; i < total; ++i) {
        cout << i + 1 << ". " << locais[i].nomerua
             << " (X: " << locais[i].coordx << ", Y: " << locais[i].coordy << ")\n";
    }

    int escolha;
    do {
        cout << "Escolha um local (1-" << total << "): ";
        cin >> escolha;
    } while (escolha < 1 || escolha > total);

    selecionado = locais[escolha - 1];
    delete[] locais;
    return true;
}
