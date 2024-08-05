#ifndef COMANDOS_H_INCLUDED
#define COMANDOS_H_INCLUDED
#include "Camada de Apresentação/ControladorasApr.h"

class ComandoIAConta {
public:
    virtual ~ComandoIAConta() = default;
    virtual void executar() = 0;             // Método por meio do qual é solicitada a execução do comando.
};

class ComandoIAContaCriar : public ComandoIAConta {
private:
    InterfaceSConta* ISConta;
    string cpfValue, nomeValue, senhaValue;
    Conta conta;
    Cpf cpf;
    Nome nome;
    Senha senha;
public:
    ComandoIAContaCriar() : ISConta(new StubSConta()) {};
    void executar() override;
};


inline void ComandoIAContaCriar::executar() {
    string inputUsuario;
    bool resultadoConta;

    cout << "--- Criacao de Conta ---" << endl;
    cout << "Digite o CPF: ";
    cin >> cpfValue;
    cout << "Digite seu Nome: ";
    cin >> nomeValue;
    cout << "Digite sua senha: ";
    cin >> senhaValue;
    while (true) {
        try {
            cpf.setValor(cpfValue);
            nome.setValor(nomeValue);
            senha.setValor(senhaValue);
            conta.setCpf(cpf);
            conta.setNome(nome);
            conta.setSenha(senha);

        } catch (std::invalid_argument& excecao) {
            cout << "Tentar novamente? [S]/[N]" << endl;
            cin >> inputUsuario;
            if (inputUsuario != "S")
                break;
        };
    };

    resultadoConta = ISConta->criar(conta);
    if (resultadoConta)
        cout << "Sucesso na criacao da Conta." << endl;

};

#endif // COMANDOS_H_INCLUDED
