#ifndef CONTROLADORASAPR_H_INCLUDED
#define CONTROLADORASAPR_H_INCLUDED
#include "../Interfaces.h"
#include "../Camada de Serviço/Banco de Dados/ConexaoBD.h"
#include "../Comandos.h"

/// @file ControladorasApr.h Arquivo contendo as Controladoras da Camada de Apresentacao.

/// Declaracao de classe Controladora para tela inicial.

class CntrlAprInicial { // 190084499
private:
    InterfaceAAut* IAAut;
    InterfaceAConta* IAConta;
    static const short SAIR         = 0;
    static const short AUTENTICAR   = 1;
    static const short CONTA        = 1;
    static const short CRIAR        = 2;
    static const short INVESTIMENTO = 2;
    short inputUsuario;
public:
    /// Construtor onde se inicia o programa.
    CntrlAprInicial();
    ~CntrlAprInicial(); /// Metodo para tela auxiliar pos autenticacao de usuario.
    void telaUsuario();
};

/// Declaracao de classe Controladora que realiza interface de Autenticacao na Camada de Apresentacao.

class CntrlAAut : public InterfaceAAut { // 190084499
private:
    InterfaceSAut* ISAut;
    string senhaValue;
    string cpfValue;
    Senha senha;
    Cpf cpf;
public:
    CntrlAAut() : ISAut(nullptr) {};
    ~CntrlAAut() {delete ISAut;};
    bool autenticar() override;

};

//---------------------------------------------------------------------------------------------------

class ComandoIAConta;

/// Declaracao de classe Controladora que realiza interface de Contas na Camada de Apresentacao.

class CntrlAConta : public InterfaceAConta { // 190084499
private:
    ComandoIAConta* comando;
    static const short SAIR      = 0;
    static const short LISTAR    = 1;
    static const short ATUALIZAR = 2;
    static const short EXCLUIR   = 3;
public:
    /// Metodo para criacao de Conta.
    void criar() override; /// Metodo para assumir o controle do fluxo do programa.
    void executar() override;
};

//---------------------------------------------------------------------------------------------------

#endif // CONTROLADORASAPR_H_INCLUDED
