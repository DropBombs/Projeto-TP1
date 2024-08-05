#include "ConexaoBD.h"

// Atributo estático.

list<ElementoResultado> ComandoSQL::listaResultado;

//---------------------------------------------------------------------------
// Implementações de métodos da classe ErroPersistencia.

EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
};

string EErroPersistencia::what() {
        return mensagem;
};

//---------------------------------------------------------------------------
// Implementações de métodos da classe ElementoResultado.

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
};

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
};

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoSQL.

void ComandoSQL::conectar() {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
};

void ComandoSQL::desconectar() {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");
};

void ComandoSQL::executar() {
        conectar();
        rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
        if(rc != SQLITE_OK){
                sqlite3_free(mensagem);
                desconectar();
                throw EErroPersistencia("Erro na execucao do comando SQL");
        };
        desconectar();
};

int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed=0;
      ElementoResultado elemento;
      int i;
      for(i=0; i<argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
};

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoLerSenha.

ComandoLerSenha::ComandoLerSenha(Cpf cpf) {
        comandoSQL = "SELECT senha FROM conta WHERE matricula = ";
        comandoSQL += cpf.getValor();
};

string ComandoLerSenha::getResultado() {
        ElementoResultado resultado;
        string senha;

        //Remover senha;
        if (listaResultado.empty())
                throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        senha = resultado.getValorColuna();

        return senha;
};

//---------------------------------------------------------------------------
// Implementações de métodos da classe ComandoPesquisarCpf.

ComandoPesquisarCpf::ComandoPesquisarCpf(Cpf cpf) {
        comandoSQL = "SELECT * FROM conta WHERE cpf = ";
        comandoSQL += cpf.getValor();
};

Conta ComandoPesquisarCpf::getResultado() {
    if (listaResultado.size() < 3)
        throw EErroPersistencia("Lista de resultados com menos de três elementos.");

    // Função auxiliar para obter e remover o último elemento da lista
    auto obterElementoERemover = [this]() {
        ElementoResultado resultado;
        if (listaResultado.empty())
            throw EErroPersistencia("Lista de resultados vazia.");
        resultado = listaResultado.back();
        listaResultado.pop_back();
        return resultado.getValorColuna();
    };

    Conta conta;

    // Remover e definir CPF
    //conta.setCpf(Cpf(obterElementoERemover()));

    // Remover e definir Nome
    //conta.setNome(Nome(obterElementoERemover()));

    // Remover e definir Senha
    //conta.setSenha(Senha(obterElementoERemover()));

    return conta;
};
