#ifndef CONTROLADORASAPR_H_INCLUDED
#define CONTROLADORASAPR_H_INCLUDED
#include "Interfaces.h"

class CntrlAAut : public InterfaceAAut {
public:
    bool autenticar(Cpf*) override;

};

#endif // CONTROLADORASAPR_H_INCLUDED
