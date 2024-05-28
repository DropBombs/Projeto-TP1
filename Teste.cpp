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

//---------------------------------------------------------------------------------------------------

void UTEstado::testeValido() {
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTEstado::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};

//---------------------------------------------------------------------------------------------------

void UTNome::testeValido(){
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTNome::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};

//---------------------------------------------------------------------------------------------------

void UTSenha::testeValido(){
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTSenha::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};

//---------------------------------------------------------------------------------------------------

void UTSetor::testeValido(){
    try {
        instancia->setValor(VALOR_VALIDO);
    } catch (const invalid_argument& excecao) {
        estado = FALHA;
    };

    if (instancia->getValor() != VALOR_VALIDO)
        estado = FALHA;
};

void UTSetor::testeInvalido() {
    try {
        instancia->setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (const invalid_argument& excecao) {
        if (instancia->getValor() == VALOR_INVALIDO)
            estado = FALHA;
    };
};

//---------------------------------------------------------------------------------------------------
/// Implementações dos Testes de Entidade.

bool TEPagamento::testeEntidade() {
    CodigoDePagamento codigoTeste;
    codigoTeste.setValor(VALOR_TESTE_CDP);
    instancia->setCodigo(codigoTeste);
    if (instancia->getCodigo().getValor() != VALOR_TESTE_CDP) {
        cout << "Erro ao inicializar Código de Pagamento";
        return false;
    };

    Data dataTeste;
    dataTeste.setValor(VALOR_TESTE_DATA);
    instancia->setData(dataTeste);
    if (instancia->getData().getValor() != VALOR_TESTE_DATA) {
        cout << "Erro ao inicializar Data.";
        return false;
    };

    Percentual percentualTeste;
    percentualTeste.setValor(VALOR_TESTE_PER);
    instancia->setPercentual(percentualTeste);
    if (instancia->getPercentual().getValor() != VALOR_TESTE_PER) {
        cout << "Erro ao inicializar Percentual.";
        return false;
    };

    Estado estadoTeste;
    estadoTeste.setValor(VALOR_TESTE_EST);
    instancia->setEstado(estadoTeste);
    if (instancia->getEstado().getValor() != VALOR_TESTE_EST) {
        cout << "Erro ao inicializar Código de Pagamento";
        return false;
    };

    return true;
};
