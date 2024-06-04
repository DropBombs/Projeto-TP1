#include "Teste.h"
#include "Dominios.h"
using namespace std;

/// Metodo para execucao dos Testes de valor valido e invalido e retorno do estado em forma de inteiro.

int UnidadeTeste::executar() {
    testeValido();
    testeInvalido();
    return estado;
};

// Implementacoes dos testes com valor valido e valor invalido para cada Dominio.

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
// Implementacoes dos Testes de Entidade.

bool TEPagamento::testeEntidade() {
    CodigoDePagamento codigoTeste;
    codigoTeste.setValor(VALOR_TESTE_CDP);
    instancia->setCodigoPagamento(codigoTeste);
    if (instancia->getCodigoPagamento().getValor() != VALOR_TESTE_CDP) {
        cout << "Erro ao inicializar C�digo de Pagamento";
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
        cout << "Erro ao inicializar C�digo de Pagamento";
        return false;
    };

    return true;
};

//---------------------------------------------------------------------------------------------------

bool TETitulo::testeEntidade() {
    CodigoDeTitulo codigoTeste;
    codigoTeste.setValor(VALOR_TESTE_CDT);
    instancia->setCodigoTitulo(codigoTeste);
    if (instancia->getCodigoTitulo().getValor() != VALOR_TESTE_CDT) {
        cout << "Erro ao inicializar C�digo de Titulo.";
        return false;
    };

    Nome nomeTeste;
    nomeTeste.setValor(VALOR_TESTE_NOME);
    instancia->setNome(nomeTeste);
    if (instancia->getNome().getValor() != VALOR_TESTE_NOME) {
        cout << "Erro ao inicializar Nome.";
        return false;
    };

    Setor setorTeste;
    setorTeste.setValor(VALOR_TESTE_SETOR);
    instancia->setSetor(setorTeste);
    if (instancia->getSetor().getValor() != VALOR_TESTE_SETOR) {
        cout << "Erro ao inicializar Setor.";
        return false;
    };

    Data emissaoTeste;
    emissaoTeste.setValor(VALOR_TESTE_EMISSAO);
    instancia->setDataEmissao(emissaoTeste);
    if (instancia->getDataEmissao().getValor() != VALOR_TESTE_EMISSAO) {
        cout << "Erro ao inicializar Data de Emissao.";
        return false;
    };

    Data vencimentoTeste;
    vencimentoTeste.setValor(VALOR_TESTE_VENC);
    instancia->setDataVencimento(vencimentoTeste);
    if (instancia->getDataVencimento().getValor() != VALOR_TESTE_VENC) {
        cout << "Erro ao inicializar Data de Vencimento.";
        return false;
    };

    Dinheiro valorTeste;
    valorTeste.setValor(VALOR_TESTE_DINHEIRO);
    instancia->setDinheiro(valorTeste);
    if (instancia->getDinheiro().getValor() != VALOR_TESTE_DINHEIRO) {
        cout << "Erro ao inicializar Dinheiro.";
        return false;
    };

    return true;
};

//---------------------------------------------------------------------------------------------------
