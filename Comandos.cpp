#include "Comandos.h"

void ComandoIAContaCriar::executar() {
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

        } catch (invalid_argument& excecao) {
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

