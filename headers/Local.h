#ifndef LOCAL_H_INCLUDED
#define LOCAL_H_INCLUDED

#include <cstddef>

struct infoLocal {
    char nomerua[50];
    float coordx;
    float coordy;
};

class Local {
private:
    char nomerua[50];
    float coordx;
    float coordy;

    static Local** listaLocal;
    static int totalLocal;

public:
    Local(); // construtor padrão
    Local(char* nome, float x, float y); // construtor parametrizado

    void setNomeRua(char nome[]);
    char* getNomeRua();

    void setX(float x);
    float getX() const;

    void setY(float y);
    float getY() const;

    void paraString(char* dest, size_t tam) const;

    infoLocal listarLocal() const;
    static infoLocal* listarTodosLocais(int& total); // metodo que retorna um ponteiro de structs para serem imprimidas no main

    static void adicionarLocal(char* nomerua, float coordx, float coordy);
    static void excluirLocal(float coordx, float coordy);

};

#endif // LOCAL_H_INCLUDED
