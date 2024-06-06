#ifndef TESTE_H
#define TESTE_H
#include <string>
#include <functional>
#include "Dominios.h"
#include "Entidades.h"

using namespace std;

/// Declaração de classe abstrata para interface de criação de testes de Dominio.


class UnidadeTeste {
public:
    virtual ~UnidadeTeste() = default;
    virtual void testeValido() = 0;
    virtual void testeInvalido() = 0;
    static constexpr short FALHA = 0;
    static constexpr short SUCESSO = 1; /// Declarações de constantes para identificação do estado.
    int estado;
    int executar();  /// Função que chama a implementação específica de cada teste.
};

/// Declarações dos Testes de Unidade dos Dominios.

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

class UTEstado : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "Inadimplente";
    string const VALOR_INVALIDO = "Imprevisto";
    ~UTEstado() {delete instancia;};
public:
    UTEstado(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

class UTNome : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "Tiago Nunes";
    string const VALOR_INVALIDO = "tiago nunes";
    ~UTNome() {delete instancia;};
public:
    UTNome(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

class UTSenha : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "184302";
    string const VALOR_INVALIDO = "123456";
    ~UTSenha() {delete instancia;};
public:
    UTSenha(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

class UTSetor : public UnidadeTeste {
private:
    Dominio* instancia;
    string const VALOR_VALIDO = "Agricultura";
    string const VALOR_INVALIDO = "mineracao";
    ~UTSetor() {delete instancia;};
public:
    UTSetor(Dominio* instancia) : instancia(instancia) {estado = SUCESSO;};
    void testeValido() override;
    void testeInvalido() override;
};

//---------------------------------------------------------------------------------------------------
/// Declaração de classe abstrata para interface de criação de testes de Entidade.

class TesteEntidade {
public:
    virtual ~TesteEntidade() = default;
    virtual bool testeEntidade() = 0;
};

/// Declarações dos Testes de Unidade das Entidades.

class TEPagamento : public TesteEntidade {
private:
    Pagamento* instancia;
    string const VALOR_TESTE_CDP = "12312312";
    string const VALOR_TESTE_DATA = "31-12-2000";
    string const VALOR_TESTE_PER = "50";
    string const VALOR_TESTE_EST = "Previsto";
public:
    TEPagamento(Pagamento* instancia) : instancia(instancia) {};
    ~TEPagamento() {delete instancia;};
    bool testeEntidade() override;
};

class TETitulo : public TesteEntidade {
private:
    Titulo* instancia;
    string const VALOR_TESTE_CDT = "LCA123BC67Z";
    string const VALOR_TESTE_NOME = "Antonio Paulo";
    string const VALOR_TESTE_SETOR = "Química e petroquímica";
    string const VALOR_TESTE_EMISSAO = "29-05-2024";
    string const VALOR_TESTE_VENC = "01-06-2024";
    string const VALOR_TESTE_DINHEIRO = "500.70";
public:
    TETitulo(Titulo* instancia) : instancia(instancia) {};
    ~TETitulo() {delete instancia;};
    bool testeEntidade() override;
};

class TEConta : public TesteEntidade {
private:
    Conta* instancia;
    string const VALOR_TESTE_CPF = "390.229.170-29";
    string const VALOR_TESTE_NOME = "Tiago Nunes";
    string const VALOR_TESTE_SENHA = "132756";
public:
    TEConta(Conta* instancia) : instancia(instancia) {};
    ~TEConta() {delete instancia;};
    bool testeEntidade() override;
};

#endif // TESTE_H
