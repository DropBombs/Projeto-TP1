#include "Teste.h"
#include "Dominios.h"
using namespace std;

/// Método para execução dos testes de valor válido e inválido e retorno do estado em forma de inteiro.

int UnidadeTeste::executar() {
    testeValido();
    testeInvalido();
    return estado;
};

/// Implementações dos testes com valor válido e valor inválido para cada dominio.

void UTPercentual::testeValido() {
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTPercentual::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};

//---------------------------------------------------------------------------------------------------

void UTMonetario::testeValido() {
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTMonetario::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};

//---------------------------------------------------------------------------------------------------

void UTCdPagamento::testeValido() {
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTCdPagamento::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};

//---------------------------------------------------------------------------------------------------

void UTCdTitulo::testeValido() {
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTCdTitulo::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};

//---------------------------------------------------------------------------------------------------

void UTCPF::testeValido() {
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTCPF::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};

//---------------------------------------------------------------------------------------------------

void UTData::testeValido() {
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTData::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};
