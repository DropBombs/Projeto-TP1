#ifndef TESTE_H
#define TESTE_H
#include <string>
#include <functional>
#include "Dominios.h"
#include "Entidades.h"

using namespace std;

/// @file Teste.h Arquivo contendo os Testes requeridos para Dominios e Entidades.

/// Declaracao de classe abstrata para interface de criacao de Testes de Dominio.

class UnidadeTeste { // 190084499
public:
    virtual ~UnidadeTeste() = default; /// Teste de valor valido a ser implementado pela classe herdada.
    virtual void testeValido() = 0; /// Teste de valor invalido a ser implementado pela classe herdada.
    virtual void testeInvalido() = 0; /// Definicao de constante para identificacao do estado.
    static constexpr short FALHA = 0; /// Definicao de constante para identificacao do estado.
    static constexpr short SUCESSO = 1; /// Declaracao de inteiro para atribuicao do resultado Teste.
    int estado; /// Funcao que chama a implementacao especifica de cada Teste de valor valido e invalido.
    /// @return Retorna estado do Teste ao final da execucao.
    int executar();
};

// Declaracoes dos Testes de Unidade dos Dominios.
/// @brief Classe para Testes do Dominio Percentual.
/// @param instancia Ponteiro de tipo Percentual para Teste.

class UTPercentual : public UnidadeTeste { // 190084499
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

/// @brief Classe para Testes do Dominio Dinheiro.
/// @param instancia Ponteiro de tipo Dinheiro para Teste.

class UTMonetario : public UnidadeTeste { // 190084499
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

/// @brief Classe para Testes do Dominio CodigoDePagamento.
/// @param instancia Ponteiro de tipo CodigoDePagamento para Teste.

class UTCdPagamento : public UnidadeTeste { // 190084499
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

/// @brief Classe para Testes do Dominio CodigoDeTitulo.
/// @param instancia Ponteiro de tipo CodigoDeTitulo para Teste.

class UTCdTitulo : public UnidadeTeste { // 190084499
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

/// @brief Classe para Testes do Dominio Cpf.
/// @param instancia Ponteiro de tipo Cpf para Teste.

class UTCPF : public UnidadeTeste { // 190084499
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

/// @brief Classe para Testes do Dominio Data.
/// @param instancia Ponteiro de tipo Data para Teste.

class UTData : public UnidadeTeste { // 190084499
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

/// @brief Classe para Testes do Dominio Estado.
/// @param instancia Ponteiro de tipo Estado para Teste.

class UTEstado : public UnidadeTeste { // 190084499
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

/// @brief Classe para Testes do Dominio Nome.
/// @param instancia Ponteiro de tipo Nome para Teste.

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

/// @brief Classe para Testes do Dominio Senha.
/// @param instancia Ponteiro de tipo Senha para Teste.

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

/// @brief Classe para Testes do Dominio Setor.
/// @param instancia Ponteiro de tipo Setor para Teste.

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
/// Declaracao de classe abstrata para interface de criacao de Testes de Entidade.

class TesteEntidade { // 190084499
public:
    virtual ~TesteEntidade() = default; /// Teste de Entidade a ser implementada pela classe herdada.
    /// @return Retorno de tipo booleano para identificacao do resultado do Teste.
    virtual bool testeEntidade() = 0;
};

// Declaracoes dos Testes de Unidade das Entidades.
/// @brief Classe para Teste da Entidade Pagamento.
/// @param instancia Ponteiro de tipo Pagamento para Teste.

class TEPagamento : public TesteEntidade { // 190084499
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

/// @brief Classe para Teste da Entidade Titulo.
/// @param instancia Ponteiro de tipo Titulo para Teste.

class TETitulo : public TesteEntidade { // 190084499
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

#endif // TESTE_H
