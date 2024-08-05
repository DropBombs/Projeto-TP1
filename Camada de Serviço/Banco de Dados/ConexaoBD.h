#ifndef CONEXAOBD_H_INCLUDED
#define CONEXAOBD_H_INCLUDED
#include "../../Entidades.h"
#include <list>
#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include "sqlite3.h"           // Incluir cabeçalho da biblioteca SQLite.

using namespace std;

/// @file ConexaoBD.h Arquivo contendo aplicacao de persistencia com SQLite.

// Declaração da classe EErroPersistencia.
/// Declaracao de classe para controle de Erro de persistencia.
class EErroPersistencia { // 200060422
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what() const;
};

//---------------------------------------------------------------------------

/// Declaracao de classe com comportamento relacional para BD.
class ElementoResultado { // 200060422
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const;
        void setValorColuna(const string&);
        string getValorColuna() const;
};

//---------------------------------------------------------------------------

/// Declaracao de classe para execucao de comandos SQL.
class ComandoSQL { // 200060422
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar();
        void desconectar();
        static int callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna);

protected:
        static list<ElementoResultado> listaResultado;
        string comandoSQL;
public:
        ComandoSQL() {
             nomeBancoDados = "trabalho2db.db";                             // Nome do banco de dados.
        }
        void executar();
};

//---------------------------------------------------------------------------

/// Declaracao de classe Comando para autenticar Cpf e Senha no BD.
class ComandoLerSenha : public ComandoSQL { // 200060422
public:
        ComandoLerSenha(Cpf);
        string getResultado();
};

/// Declaracao de classe Comando para criar Conta no BD.
class ComandoCriarConta : public ComandoSQL { // 200060422
public:
    ComandoCriarConta(Conta);
};

/// Declaracao de classe Comando para atualizar dados da Conta no BD.
class ComandoAtualizarConta : public ComandoSQL { // 200060422
public:
    ComandoAtualizarConta(Conta);
};

/// Declaracao de classe Comando para excluir Conta no BD.
class ComandoExcluirConta : public ComandoSQL { // 200060422
public:
    ComandoExcluirConta(Conta);
};

/// Declaracao de classe Comando para listar dados da Conta no BD.
class ComandoListarConta : public ComandoSQL { // 200060422
public:
    ComandoListarConta(Conta);
};

//---------------------------------------------------------------------------

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
};

#endif // CONEXAOBD_H_INCLUDED
