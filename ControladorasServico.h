#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED
#include "Interfaces.h"

class CntrlSAut : public InterfaceSAut {
public:
    bool autenticar(Cpf, Senha) override;
};

class CntrlSConta : public InterfaceSConta {
public:
    bool criar(Conta) override;
    bool recuperar(Conta*) override;
    bool atualizar(Conta) override;
    bool excluir(Cpf) override;
};

class CntrlSTitulo : public InterfaceSTitulo {
public:
    bool criar(Titulo) override;
    bool recuperar(Titulo*) override;
    bool atualizar(Titulo) override;
    bool excluir(CodigoDeTitulo) override;
};

class CntrlSPagamento : public InterfaceSPagamento {
public:
    virtual bool criar(Pagamento) override;
    virtual bool recuperar(Pagamento*) override;
    virtual bool atualizar(Pagamento) override;
    virtual bool excluir(CodigoDePagamento) override;
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
