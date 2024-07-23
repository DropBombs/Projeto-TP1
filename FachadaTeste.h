#ifndef FACHADATESTE_H_INCLUDED
#define FACHADATESTE_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>
#include "Teste.h"

using namespace std;

class FachadaTestes {
private:
    vector<string> dominiosTeste = {"Dinheiro", "Percentual", "CodigoDePagamento",
                                    "CodigoDeTitulo", "Cpf", "Data", "Estado",
                                    "Nome", "Senha", "Setor"};
    Pagamento pagamento;
    Conta conta;
    Titulo titulo;

public:
    void executarTestes();
};

inline void FachadaTestes::executarTestes() {

    // Executando os testes nos Dominios.

    InicializadorTestes::bateriaTestesDominio(dominiosTeste);

    // Executando os testes nas Entidades.

    TEPagamento testePagamento(&pagamento);
    TEConta testeConta(&conta);
    TETitulo testeTitulo(&titulo);

    InicializadorTestes::bateriaTestesEntidades(testeConta, testePagamento, testeTitulo);

};

#endif // FACHADATESTE_H_INCLUDED
