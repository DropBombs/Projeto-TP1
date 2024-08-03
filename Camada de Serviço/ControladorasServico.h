#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED
#include "../Interfaces.h"
/*
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
    bool criar(Pagamento) override;
    bool recuperar(Pagamento*) override;
    bool atualizar(Pagamento) override;
    bool excluir(CodigoDePagamento) override;
};


class CntrlSArmazenamento {
private:
    static CntrlSArmazenamento* instancia;
    CntrlSArmazenamento() {};
public:
    static CntrlSArmazenamento* getInstancia() {
        if (instancia == nullptr)
            instancia = new CntrlSArmazenamento();
        return instancia;
    };
};
*/
#endif // CONTROLADORASSERVICO_H_INCLUDED
