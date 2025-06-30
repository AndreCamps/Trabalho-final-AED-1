#include "Pedido.h"
#include <cstring>

// Inicialização de membros estáticos
int Pedido::proximoId = 1;
Pedido** Pedido::listaPedidos = nullptr;
int Pedido::totalPedidos = 0;

Pedido::Pedido() : id(proximoId++) {
    origem = Local();
    destino = Local();
    peso = 0.01;
}

Pedido::Pedido(const Local& orig, const Local& dest, float p)
    : id(proximoId++), origem(orig), destino(dest) {
    peso = (p > 0) ? p : 0.01;
}

int Pedido::getId() const {
    return id;
}

const Local& Pedido::getOrigem() const {
    return origem;
}

const Local& Pedido::getDestino() const {
    return destino;
}

float Pedido::getPeso() const {
    return peso;
}

void Pedido::setId(int i) {
    if (i > 0)
        id = i;
}

void Pedido::setPeso(float p) {
    if (p > 0)
        peso = p;
}

void Pedido::setOrigem(Local& loc) {
    origem = loc;
}

void Pedido::setDestino(Local& loc) {
    destino = loc;
}

infoPedido Pedido::listarPedido() const {
    infoPedido info;
    info.id = id;
    info.peso = peso;

    origem.paraString(info.localOrigem, sizeof(info.localOrigem));
    destino.paraString(info.localDestino, sizeof(info.localDestino));

    return info;
}

infoPedido* Pedido::listarTodosPedidos(int& total)
{
    total = totalPedidos;
    if(total == 0)
        return nullptr;
    infoPedido* lista = new infoPedido[total];

    for(int i=0;i<total;i++)
    {
        lista[i] = listaPedidos[i]->listarPedido();
    }
    return lista;
}



void Pedido::adicionarPedido(const Local& origem, const Local& destino, float peso) {
    Pedido** novoVetor = new Pedido*[totalPedidos + 1];
    if(novoVetor = nullptr)
//        throw exception("n");

    for (int i = 0; i < totalPedidos; i++) {
        novoVetor[i] = listaPedidos[i];
    }

    if (origem.getX() != 0 || destino.getX() != 0 || peso != 0.01)
        novoVetor[totalPedidos] = new Pedido(origem, destino, peso);
    else
        novoVetor[totalPedidos] = new Pedido();

    delete[] listaPedidos;
    listaPedidos = novoVetor;
    totalPedidos++;
}

void Pedido::excluirPedido(int id) {
    for (int i = 0; i < totalPedidos; i++) {
        if (listaPedidos[i]->getId() == id) {
            delete listaPedidos[i];

            for (int j = i; j < totalPedidos - 1; j++) {
                listaPedidos[j] = listaPedidos[j + 1];
            }

            totalPedidos--;

            Pedido** novoVetor = new Pedido*[totalPedidos];
            for (int k = 0; k < totalPedidos; k++) {
                novoVetor[k] = listaPedidos[k];
            }
            if(novoVetor = nullptr)
 //

            delete[] listaPedidos;
            listaPedidos = novoVetor;

            return;
        }
 //   throw out_of_range("pedido não encontrado")
    }
}


