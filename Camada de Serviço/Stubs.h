#ifndef STUBS_H_INCLUDED
#define STUBS_H_INCLUDED
#include "../Interfaces.h"

class StubSAut : public InterfaceSAut {
private:
    const string cpfAux = "529.982.247-25";
    const string senhaAux = "184302";
    Cpf cpfStub;
    Senha senhaStub;
public:
    bool autenticar(Cpf, Senha) override;
};

inline bool StubSAut::autenticar(Cpf cpf, Senha senha) {
    cpfStub.setValor(cpfAux);
    senhaStub.setValor(senhaAux);
    return (cpf.getValor() == cpfStub.getValor() && senha.getValor() == senhaStub.getValor());
};

#endif // STUBS_H_INCLUDED
