#ifndef FACHADATESTE_H_INCLUDED
#define FACHADATESTE_H_INCLUDED
#include <vector>
#include <string>
#include <iostream>
#include "Teste.h"

using namespace std;

/// @file FachadaTeste.h Arquivo contendo fachada para execucao de Testes.

/// Declaracao de classe Fachada para centralizacao do processo de Teste.
class FachadaTestes {
private:
    vector<string> dominiosTeste = {"Dinheiro", "Percentual", "CodigoDePagamento",
                                    "CodigoDeTitulo", "Cpf", "Data", "Estado",
                                    "Nome", "Senha", "Setor"};
    Pagamento pagamento;
    Conta conta;
    Titulo titulo;

public:
    /// Metodo pelo qual e executado os Testes.
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
