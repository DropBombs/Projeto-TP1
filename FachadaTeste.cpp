#include "FachadaTeste.h"

void FachadaTestes::executarTestes() {

    // Executando os testes nos Dominios.

    InicializadorTestes::bateriaTestes(dominiosTeste);

    // Executando os testes nas Entidades.

    bool resultadoTeste;

    resultadoTeste = testePagamento.testeEntidade();
    if (resultadoTeste)
        cout << "Sucesso nos testes de Pagamento." << endl;

    resultadoTeste = testeTitulo.testeEntidade();
    if (resultadoTeste)
        cout << "Sucesso nos testes de Titulo." << endl;

    resultadoTeste = testeConta.testeEntidade();
    if (resultadoTeste)
        cout << "Sucesso nos testes de Conta." << endl;


};
