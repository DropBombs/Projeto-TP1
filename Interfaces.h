#ifndef INTERFACES_H
#define INTERFACES_H
#include "Entidades.h"

// Declarações de interfaces da camada de apresentação.

class InterfaceAAut {
public:
    virtual ~InterfaceAAut() = default;
    virtual bool autenticar(Cpf*) = 0;

};

class InterfaceAConta {
public:
    virtual ~InterfaceAConta() = default;
    virtual void criar() = 0;
    virtual int executar(Cpf) = 0;
};

class InterfaceAInv {
public:
    virtual ~InterfaceAInv() = default;
};

// Declarações de interfaces da camada de serviço.

class InterfaceSAut {
public:
    virtual ~InterfaceSAut() = default;
};

class InterfaceSConta {
public:
    virtual ~InterfaceSConta() = default;
};

class InterfaceSInv {
public:
    virtual ~InterfaceSInv() = default;
};

#endif // INTERFACES_H
