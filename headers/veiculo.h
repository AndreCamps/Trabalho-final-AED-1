#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED

#include "Local.h"

struct InfoVeiculo {
    char placa[10];
    char modelo[50];
    bool disponivel;
    char local[200];
};

class Veiculo {
private:
    char placa[10];
    char modelo[50];
    Local localveiculo;
    bool disponivel;

    static Veiculo** listaVeiculos;
    static int totalVeiculos;

public:
    Veiculo();
    Veiculo(const char* novaplaca, const char* novomodelo, const Local& loc, bool d = true);

    void setDisponiv(bool a);
    void setLocal(const Local& loc);

    const char* getPlaca() const;
    const char* getModelo() const;
    const Local& getLocal() const;
    bool getDisponivel() const;

    InfoVeiculo listarVeiculo() const;
    static InfoVeiculo* listarTodosVeiculos(int& total); // metodo que retorna um ponteiro de structs para serem imprimidas no main

    static void adicionarVeiculo(const char* placa = "", const char* modelo = "", const Local& localveiculo = Local(), bool d = true);
    static void excluirVeiculo(char* p);
};

#endif // VEICULO_H_INCLUDED
