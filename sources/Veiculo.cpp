#include "Veiculo.h"
#include <cstring>
#include <iostream>

using namespace std;

// Inicialização dos membros estáticos
Veiculo** Veiculo::listaVeiculos = nullptr;
int Veiculo::totalVeiculos = 0;

Veiculo::Veiculo() {
    strncpy(placa, "XXX-XXXX", sizeof(placa));
    placa[sizeof(placa) - 1] = '\0';

    strncpy(modelo, "Novo Modelo", sizeof(modelo));
    modelo[sizeof(modelo) - 1] = '\0';

    localveiculo = Local();
    disponivel = true;
}

Veiculo::Veiculo(const char* novaplaca, const char* novomodelo, const Local& loc, bool d)
    : localveiculo(loc), disponivel(d) {
    strncpy(placa, novaplaca, sizeof(placa) - 1);
    placa[sizeof(placa) - 1] = '\0';

    strncpy(modelo, novomodelo, sizeof(modelo) - 1);
    modelo[sizeof(modelo) - 1] = '\0';
}

void Veiculo::setDisponiv(bool a) {
    disponivel = a;
}

void Veiculo::setLocal(const Local& loc) {
    localveiculo = loc;
}

const char* Veiculo::getPlaca() const {
    return placa;
}

const char* Veiculo::getModelo() const {
    return modelo;
}

const Local& Veiculo::getLocal() const {
    return localveiculo;
}

bool Veiculo::getDisponivel() const {
    return disponivel;
}

InfoVeiculo Veiculo::listarVeiculo() const {
    InfoVeiculo info;

    strncpy(info.placa, placa, sizeof(info.placa) - 1);
    info.placa[sizeof(info.placa) - 1] = '\0';

    strncpy(info.modelo, modelo, sizeof(info.modelo) - 1);
    info.modelo[sizeof(info.modelo) - 1] = '\0';

    info.disponivel = disponivel;

    localveiculo.paraString(info.local, sizeof(info.local));

    return info;
}

InfoVeiculo* Veiculo::listarTodosVeiculos(int& total)
{
    total = totalVeiculos;
    if(total == 0)
        return nullptr;
    InfoVeiculo* lista = new InfoVeiculo[total];

    for(int i=0;i<total;i++)
    {
        lista[i] = listaVeiculos[i]->listarVeiculo();
    }
    return lista;
}


void Veiculo::adicionarVeiculo(const char* placa, const char* modelo, const Local& localveiculo, bool d) {
    Veiculo** novoVetor = new Veiculo*[totalVeiculos + 1];
    for (int i = 0; i < totalVeiculos; i++) {
        novoVetor[i] = listaVeiculos[i];
    }

    if (placa[0] != '\0' || modelo[0] != '\0' || localveiculo.getX() != 0 || d != false)
        novoVetor[totalVeiculos] = new Veiculo(placa, modelo, localveiculo, d);
    else
        novoVetor[totalVeiculos] = new Veiculo();

    delete[] listaVeiculos;
    listaVeiculos = novoVetor;
    totalVeiculos++;
}

void Veiculo::excluirVeiculo(char* p) {
    for (int i = 0; i < totalVeiculos; i++) {
        if (strcmp(listaVeiculos[i]->getPlaca(), p) == 0) {
            delete listaVeiculos[i];

            for (int j = i; j < totalVeiculos - 1; j++) {
                listaVeiculos[j] = listaVeiculos[j + 1];
            }

            totalVeiculos--;

            Veiculo** novoVetor = new Veiculo*[totalVeiculos];
            for (int k = 0; k < totalVeiculos; k++) {
                novoVetor[k] = listaVeiculos[k];
            }

            delete[] listaVeiculos;
            listaVeiculos = novoVetor;

            break;
        }
    }
}


