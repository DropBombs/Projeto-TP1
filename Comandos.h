#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED
#include "Camada de Apresentação/ControladorasApr.h"
#include "Camada de Serviço/ControladorasServico.h"

using namespace std;

/// @file Comandos.h Arquivo contendo as classes Comando para direcionar o fluxo do programa.

/// Declaracao de classe abstrata para polimorfismo do Comando adequado.
class ComandoIAConta { // 190084499
public:
    virtual ~ComandoIAConta() = default; /// Metodo por meio do qual e solicitada a execucao do comando.
    virtual void executar() = 0;
};

/// Declaracao de classe Comando para criar Conta.
class ComandoIAContaCriar : public ComandoIAConta { // 190084499
private:
    InterfaceSConta* ISConta;
    string cpfValue, nomeValue, senhaValue;
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    ComandoIAContaCriar() : ISConta(nullptr) {};
    ~ComandoIAContaCriar() {delete ISConta;}; /// Metodo por meio do qual e solicitada a execucao do comando.
    void executar() override;
};

/// Declaracao de classe Comando para atualizar Conta.
class ComandoIAContaAtualizar : public ComandoIAConta {
private:
    InterfaceSConta* ISConta;
    string cpfValue, nomeValue, senhaValue;
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    ComandoIAContaAtualizar() : ISConta(nullptr) {};
    ~ComandoIAContaAtualizar() {delete ISConta;}; /// Metodo por meio do qual e solicitada a execucao do comando.
    void executar() override;
};

/// Declaracao de classe Comando para excluir Conta.
class ComandoIAContaExcluir : public ComandoIAConta {
private:
    InterfaceSConta* ISConta;
    string cpfValue, nomeValue, senhaValue;
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    ComandoIAContaExcluir() : ISConta(nullptr) {};
    ~ComandoIAContaExcluir() {delete ISConta;}; /// Metodo por meio do qual e solicitada a execucao do comando.
    void executar() override;
};

/// Declaracao de classe Comando para listar dados da Conta.
class ComandoIAContaListar : public ComandoIAConta {
private:
    InterfaceSConta* ISConta;
    string cpfValue, nomeValue, senhaValue;
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    ComandoIAContaListar() : ISConta(nullptr) {}; /// Metodo por meio do qual e solicitada a execucao do comando.
    ~ComandoIAContaListar() {delete ISConta;};
    void executar() override;
};

#endif // COMANDOS_H_INCLUDED
