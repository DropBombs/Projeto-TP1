#ifndef CONTROLADORASAPR_H_INCLUDED
#define CONTROLADORASAPR_H_INCLUDED
#include "../Interfaces.h"
#include "../Camada de Serviço/Banco de Dados/ConexaoBD.h"
#include "../Comandos.h"

/// Declaracao de classe Controladora que realiza interface de Autenticacao na Camada de Apresentacao.
class CntrlAprInicial {
private:
    InterfaceAAut* IAAut;
    InterfaceAConta* IAConta;
    // InterfaceAInvestimento* IAInv;
    static const short SAIR         = 0;
    static const short AUTENTICAR   = 1;
    static const short CONTA        = 1;
    static const short CRIAR        = 2;
    static const short INVESTIMENTO = 2;
    short inputUsuario;
public:
    CntrlAprInicial();
    ~CntrlAprInicial();
    void telaUsuario();
};

class CntrlAAut : public InterfaceAAut { // 190084499
private:
    InterfaceSAut* ISAut;
    string senhaValue;
    string cpfValue;
    Senha senha;
    Cpf cpf;
    bool resultadoAut;
public:
    CntrlAAut() : ISAut(nullptr) {};
    ~CntrlAAut() {delete ISAut;};
    bool autenticar() override;

};

//---------------------------------------------------------------------------------------------------

class ComandoIAConta;

class CntrlAConta : public InterfaceAConta {
private:
    ComandoIAConta* comando;
    static const short SAIR      = 0;
    static const short RECUPERAR = 1;
    static const short ATUALIZAR = 2;
    static const short EXCLUIR   = 3;
    static const short ERRO      = -1;
public:
    void criar() override;
    void executar() override;
};

//---------------------------------------------------------------------------------------------------

/*
class CntrlAInv : public InterfaceAInv {
public:

*/
#endif // CONTROLADORASAPR_H_INCLUDED
