#include "ControladorasApr.h"

using namespace std;

CntrlAprInicial::CntrlAprInicial() {
    cout << "--- Inicio do sistema CRUD ---" << endl;
    cout << "Para se autenticar escolha a opcao " << AUTENTICAR << endl;
    cout << "Para criar uma nova conta escolha a opcao " << CRIAR << endl;
    cout << "Para terminar a execucao do programa escolha a opcao " << SAIR << endl;
    cout << "Digite sua escolha: ";
    cin >> inputUsuario;
    switch (inputUsuario) {
        case SAIR:
            exit(0);
        case AUTENTICAR:
            IAAut->autenticar();
        case CRIAR:
            IAConta->criar();
    };

    // Próxima tela pós usuário autenticado.
    telaUsuario();
};

CntrlAprInicial::~CntrlAprInicial() {
    delete IAAut;
    delete IAConta;
};

void CntrlAprInicial::telaUsuario() {
    cout << "--- Usuario autenticado ---" << endl;
    cout << "Para acessar sua Conta escolha a opcao " << CONTA << endl;
    cout << "Para acessar seus Investimentos escolha a opcao " << INVESTIMENTO << endl;
    cout << "Para sair da sua Conta escolha a opcao " << SAIR << endl;
    cout << "Digite sua escolha: ";
    cin >> inputUsuario;
    switch (inputUsuario) {
        case SAIR:
            exit(0);
        case CONTA:
            IAConta->executar();
        case INVESTIMENTO:
            exit(0);
            // IAInv->executar();
    };
};

bool CntrlAAut::autenticar() {
    cout << "--- Autenticacao ---" << endl;
    resultadoAut = false;
    while (!resultadoAut) {
        cout << "Digite o seu CPF: ";
        cin >> cpfValue;
        cout << "Digite a Senha: ";
        cin >> senhaValue;
        try {
            senha.setValor(senhaValue);
            cpf.setValor(cpfValue);
            resultadoAut = true;
        } catch (const invalid_argument& excecao) {
            cout << endl << "Tente novamente." << endl;
        };

    };

    resultadoAut = ISAut->autenticar(cpf, senha);
    if (resultadoAut) {
        cout << "Autenticacao bem-sucedida!" << std::endl;
        return true;
    } else {
        cout << "Autenticacao falhou. CPF ou Senha incorretos." << std::endl;
        return false;
    }
};

//---------------------------------------------------------------------------------------------------

void CntrlAConta::criar() {
    comando = new ComandoIAContaCriar();
    comando->executar();
};

void CntrlAConta::executar() {
    int inputUsuario;
    bool sair = false;
    while (!sair) {
        cout << "--- Conta ---" << endl;
        cout << "Para recuperar e ler dados de uma conta, escolha a opcao " << RECUPERAR << endl;
        cout << "Para atualizar dados de uma conta, escolha a opcao " << ATUALIZAR << endl;
        cout << "Para excluir uma conta, escolha a opcao " << EXCLUIR << endl;
        cout << "Para voltar, escolha a opcao " << SAIR << endl;
        cout << "Digite sua escolha: ";
        cin >> inputUsuario;
        switch (inputUsuario) {
            case SAIR:
                sair = true;
            case RECUPERAR:
                exit(0);
            case ATUALIZAR:
                exit(0);
            case EXCLUIR:
                exit(0);
            default:
                cout << ERRO;
        };
    };
};
