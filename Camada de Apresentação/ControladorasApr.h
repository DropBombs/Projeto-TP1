#ifndef CONTROLADORASAPR_H_INCLUDED
#define CONTROLADORASAPR_H_INCLUDED
#include "../Interfaces.h"
#include "../Camada de Serviço/Stubs.h"

/// Declaracao de classe Controladora que realiza interface de Autenticacao na Camada de Apresentacao.

class CntrlAAut : public InterfaceAAut { // 190084499
private:
    InterfaceSAut* ISAut;
    string valorSenha;
    Senha senha;
public:
    CntrlAAut() : ISAut(new StubSAut()) {};
    ~CntrlAAut() {delete ISAut;};
    bool autenticar(Cpf*) override;

};

/*
class CntrlAConta : public InterfaceAConta {
public:
    void criar() override;
    int executar(Cpf) override;
};

class CntrlAInv : public InterfaceAInv {
public:

*/
#endif // CONTROLADORASAPR_H_INCLUDED
