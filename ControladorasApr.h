#ifndef CONTROLADORASAPR_H_INCLUDED
#define CONTROLADORASAPR_H_INCLUDED
#include "Interfaces.h"

class CntrlAAut : public InterfaceAAut {
public:
    bool autenticar(Cpf*) override;

};

class CntrlAConta : public InterfaceAConta {
public:
    void criar() override;
    int executar(Cpf) override;
};

class CntrlAInv : public InterfaceAInv {
public:


#endif // CONTROLADORASAPR_H_INCLUDED
