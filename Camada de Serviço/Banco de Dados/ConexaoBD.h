#ifndef CONEXAOBD_H_INCLUDED
#define CONEXAOBD_H_INCLUDED
#include "../../Dominios.h"
#include "../../Entidades.h"
#include <list>
#include <iostream>
#include <conio.h>
#include <string>
#include <stdio.h>
#include "sqlite3.h"           // Incluir cabeçalho da biblioteca SQLite.

using namespace std;

// Declaração da classe EErroPersistencia.

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};
//---------------------------------------------------------------------------
// Declaração da classe ElementoResultado.

class ElementoResultado {
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
// Declaração da classe ComandoSQL.

class ComandoSQL {
private:
        const char *nomeBancoDados;
        sqlite3 *bd;
        char *mensagem;
        int rc;
        void conectar();
        void desconectar();
        static int callback(void *, int, char **, char **);

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
// Declaração da classe ComandoLerSenha.

class ComandoLerSenha : public ComandoSQL {
public:
        ComandoLerSenha(Cpf);
        string getResultado();
};
//---------------------------------------------------------------------------
//Classe ComandoPesquisarCpf.

class ComandoPesquisarCpf : public ComandoSQL {
public:
        ComandoPesquisarCpf(Cpf);
        Conta getResultado();
};
//---------------------------------------------------------------------------
// Implementações de métodos.

inline string ElementoResultado::getNomeColuna() const {
        return nomeColuna;
}

inline string ElementoResultado::getValorColuna() const {
        return valorColuna;
}


#endif // CONEXAOBD_H_INCLUDED
