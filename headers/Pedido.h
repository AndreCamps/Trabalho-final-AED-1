#ifndef PEDIDO_H_INCLUDED
#define PEDIDO_H_INCLUDED

#include "Local.h"

struct infoPedido {
    int id;
    float peso;
    char localOrigem[200];
    char localDestino[200];
};

class Pedido {
private:
    int id;
    static int proximoId;
    Local origem;
    Local destino;
    float peso;

    static Pedido** listaPedidos;
    static int totalPedidos;

public:
    Pedido(); // Construtor padrão
    Pedido(const Local& orig, const Local& dest, float p); // Construtor parametrizado

    int getId() const;
    const Local& getOrigem() const;
    const Local& getDestino() const;
    float getPeso() const;

    void setId(int i);
    void setPeso(float p);
    void setOrigem(Local& loc);
    void setDestino(Local& loc);

    infoPedido listarPedido() const;
    static infoPedido* listarTodosPedidos(int& total); // metodo que retorna um ponteiro de structs para serem imprimidas no main


    static void adicionarPedido(const Local& origem = Local(), const Local& destino = Local(), float peso = 0.01);
    static void excluirPedido(int id);
};

#endif // PEDIDO_H_INCLUDED
