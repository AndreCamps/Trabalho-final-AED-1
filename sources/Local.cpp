#include "Local.h"
#include <cstring>
#include <cstdio>

// Inicialização dos membros estáticos
Local** Local::listaLocal = nullptr;
int Local::totalLocal = 0;

Local::Local() {
    strcpy(nomerua, "Novo Local");
    coordx = 0;
    coordy = 0;
}

Local::Local(char* nome, float x, float y) {
    setNomeRua(nome);
    setX(x);
    setY(y);
}

void Local::setNomeRua(char nome[]) {
    strncpy(nomerua, nome, sizeof(nomerua) - 1);
    nomerua[sizeof(nomerua) - 1] = '\0';
}

char* Local::getNomeRua() {
    return nomerua;
}

void Local::setX(float x) {
    coordx = x;
}

float Local::getX() const {
    return coordx;
}

void Local::setY(float y) {
    coordy = y;
}

float Local::getY() const {
    return coordy;
}

void Local::paraString(char* dest, size_t tam) const {
    snprintf(dest, tam, "%s, %f, %f", nomerua, coordx, coordy);
}

infoLocal Local::listarLocal() const {
    infoLocal info;

    strncpy(info.nomerua, nomerua, sizeof(info.nomerua) - 1);
    info.nomerua[sizeof(info.nomerua) - 1] = '\0';
    info.coordx = coordx;
    info.coordy = coordy;

    return info;
}

infoLocal* Local::listarTodosLocais(int& total)
{
    total = totalLocal;
    if(total == 0)
        return nullptr;
    infoLocal* lista = new infoLocal[total];

    for(int i=0;i<totalLocal;i++)
    {
        lista[i] = listaLocal[i]->listarLocal();
    }
    return lista;
}

void Local::adicionarLocal(char* nomerua, float coordx, float coordy) {
    Local** novoVetor = new Local*[totalLocal + 1];

    for (int i = 0; i < totalLocal; i++) {
        novoVetor[i] = listaLocal[i];
    }

    if (nomerua[0] != '\0' || coordx != 0 || coordy != 0)
        novoVetor[totalLocal] = new Local(nomerua, coordx, coordy);
    else
        novoVetor[totalLocal] = new Local();

    delete[] listaLocal;
    listaLocal = novoVetor;
    totalLocal++;
}

void Local::excluirLocal(float coordx, float coordy) {
    for (int i = 0; i < totalLocal; i++) {
        if (listaLocal[i]->getX() == coordx && listaLocal[i]->getY() == coordy) {
            delete listaLocal[i];

            for (int j = i; j < totalLocal - 1; j++) {
                listaLocal[j] = listaLocal[j + 1];
            }

            totalLocal--;

            Local** novoVetor = new Local*[totalLocal];
            for (int k = 0; k < totalLocal; k++) {
                novoVetor[k] = listaLocal[k];
            }

            delete[] listaLocal;
            listaLocal = novoVetor;

            return;
        }
    }
}




