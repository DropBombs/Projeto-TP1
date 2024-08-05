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

class StubSConta : public InterfaceSConta {
private:
    const string cpfAux = "529.982.247-25";
    const string nomeAux = "Antonio";
    const string senhaAux = "184302";
    Cpf cpfStub;
    Nome nomeStub;
    Senha senhaStub;
public:
    bool criar(Conta) override;
    bool recuperar(Conta*) override;
    bool atualizar(Conta) override;
    bool excluir(Cpf) override;

};

inline bool StubSConta::criar(Conta contaStub) {
    cpfStub.setValor(cpfAux);
    nomeStub.setValor(nomeAux);
    senhaStub.setValor(senhaAux);
    contaStub.setCpf(cpfStub);
    contaStub.setNome(nomeStub);
    contaStub.setSenha(senhaStub);
    return (contaStub.getCpf().getValor() == cpfAux && contaStub.getNome().getValor() == nomeAux
            && contaStub.getSenha().getValor() == senhaAux);

};

inline bool StubSConta::recuperar(Conta* conta) {
    cout << conta->getId();
    return true;
};

inline bool StubSConta::atualizar(Conta) {
    return true;
};

inline bool StubSConta::excluir(Cpf) {
    return true;
};


#endif // STUBS_H_INCLUDED
