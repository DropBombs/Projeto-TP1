#ifndef INTERFACES_H
#define INTERFACES_H
#include "Entidades.h"

// Declarações de interfaces da camada de apresentação.

class InterfaceAAut {
public:
    virtual ~InterfaceAAut() = default;
    virtual bool autenticar() = 0;

};

class InterfaceAConta {
public:
    virtual ~InterfaceAConta() = default;
    virtual void criar() = 0;
    virtual void executar() = 0;

};

class InterfaceAInvestimentos {
public:
    virtual ~InterfaceAInvestimentos() = default;
    virtual void executar(Cpf) = 0  ;
};

// Declarações de interfaces da camada de serviço.

//---------------------------------------------------------------------------------------------------

class InterfaceSAut {
public:
    virtual ~InterfaceSAut() = default;
    virtual bool autenticar(Cpf, Senha) = 0;
};

class InterfaceSConta {
public:
    virtual ~InterfaceSConta() = default;
    virtual bool criar(Conta) = 0;
    virtual bool recuperar(Conta*) = 0;
    virtual bool atualizar(Conta) = 0;
    virtual bool excluir(Cpf) = 0;
};

/*
class InterfaceSTitulo {
public:
    virtual ~InterfaceSTitulo() = default;
    virtual bool criar(Titulo) = 0;
    virtual bool recuperar(Titulo*) = 0;
    virtual bool atualizar(Titulo) = 0;
    virtual bool excluir(CodigoDeTitulo) = 0;
};

class InterfaceSPagamento {
public:
    virtual ~InterfaceSPagamento() = default;
    virtual bool criar(Pagamento) = 0;
    virtual bool recuperar(Pagamento*) = 0;
    virtual bool atualizar(Pagamento) = 0;
    virtual bool excluir(CodigoDePagamento) = 0;
};
*/

#endif // INTERFACES_H
