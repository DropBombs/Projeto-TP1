#ifndef TESTE_H
#define TESTE_H
#include <string>
#include <vector>
#include <functional>
#include <stdexcept>
#include "Dominios.h"
using namespace std;

/// Declaração de classe abstrata para interface de criação de testes.

class UnidadeTeste {
public:
    virtual ~UnidadeTeste() = default;
    virtual void testeValido() = 0;
    virtual void testeInvalido() = 0;
    static constexpr short FALHA = 0;
    static constexpr short SUCESSO = 1;
    int estado;
    int executar();  /// Função que chama a implementação específica de cada teste.
};

class UTPercentual : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "30";
    string const VALOR_INVALIDO = "101";
    ~UTPercentual() {delete instancia;}

public:
    UTPercentual(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

class UTMonetario : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "2.52";
    string const VALOR_INVALIDO = "-1.50";
    ~UTMonetario() {delete instancia;}

public:
    UTMonetario(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

class UTCdPagamento : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "12345678";
    string const VALOR_INVALIDO = "01234567";
    ~UTCdPagamento() {delete instancia;};
public:
    UTCdPagamento(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

class UTCdTitulo : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "CDB12345678";
    string const VALOR_INVALIDO = "TES01234567";
    ~UTCdTitulo() {delete instancia;};
public:
    UTCdTitulo(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

class UTCPF : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "529.982.247-25";
    string const VALOR_INVALIDO = "123.456.789.09";
    ~UTCPF() {delete instancia;};
public:
    UTCPF(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

class UTData : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "29-02-2024";
    string const VALOR_INVALIDO = "31-04-2023";
    ~UTData() {delete instancia;};
public:
    UTData(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

#endif // TESTE_H
