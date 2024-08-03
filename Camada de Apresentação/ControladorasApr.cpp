#include "ControladorasApr.h"
using namespace std;

bool CntrlAAut::autenticar(Cpf* cpf) {
    cout << "--- Autenticacao ---" << endl;
    bool resultado = false;
    while (true) {
        cout << "Digite a Senha: ";
        cin >> valorSenha;
        try {
            senha.setValor(valorSenha);
            resultado = true;
        } catch (const invalid_argument& excecao) {
            cout << endl << "Tente novamente." << endl;
        };

        if (resultado)
            break;
    };
    bool resultadoAut = ISAut->autenticar(*cpf, senha);
    if (resultadoAut) {
        cout << "Autenticacao bem-sucedida!" << std::endl;
        return true;
    } else {
        cout << "Autenticacao falhou. CPF ou Senha incorretos." << std::endl;
        return false;
    }
};
