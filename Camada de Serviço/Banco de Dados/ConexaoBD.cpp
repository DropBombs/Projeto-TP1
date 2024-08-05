#include "ConexaoBD.h"

// Atributo estático.
list<ElementoResultado> ComandoSQL::listaResultado;

// Implementações de métodos da classe ErroPersistencia.
EErroPersistencia::EErroPersistencia(string mensagem) : mensagem(mensagem) {}

string EErroPersistencia::what() const {
    return mensagem;
}

// Implementações de métodos da classe ElementoResultado.
void ElementoResultado::setNomeColuna(const string& nomeColuna) {
    this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna) {
    this->valorColuna = valorColuna;
}

// Implementações de métodos da classe ComandoSQL.
void ComandoSQL::conectar() {
    rc = sqlite3_open(nomeBancoDados, &bd);
    if (rc != SQLITE_OK) {
        throw EErroPersistencia("Erro na conexão ao banco de dados: " + string(sqlite3_errmsg(bd)));
    }
}

void ComandoSQL::desconectar() {
    rc = sqlite3_close(bd);
    if (rc != SQLITE_OK) {
        throw EErroPersistencia("Erro na desconexão ao banco de dados");
    }
}

void ComandoSQL::executar() {
    conectar();
    rc = sqlite3_exec(bd, comandoSQL.c_str(), callback, 0, &mensagem);
    if (rc != SQLITE_OK) {
        sqlite3_free(mensagem);
        desconectar();
        throw EErroPersistencia("Erro na execução do comando SQL: " + string(mensagem));
    }
    cout << "Consulta executada com sucesso." << endl;

    // Verificar conteúdo da listaResultado.

    for (const auto& elemento : listaResultado) {
        cout << "Nome da Coluna: " << elemento.getNomeColuna() << ", Valor da Coluna: " << elemento.getValorColuna() << endl;
    }

    desconectar();
}


int ComandoSQL::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna) {
    NotUsed = 0;
    cout << "Callback chamado." << endl; // Log adicional para verificação
    ElementoResultado elemento;
    for (int i = 0; i < argc; i++) {
        elemento.setNomeColuna(nomeColuna[i] ? nomeColuna[i] : "NULL");
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i] : "NULL");
        listaResultado.push_back(elemento);

        // Adicionar log para depuração
        cout << "Callback - Nome da Coluna: " << nomeColuna[i] << ", Valor da Coluna: " << (valorColuna[i] ? valorColuna[i] : "NULL") << endl;
    }
    return 0;
}

// Implementações de métodos da classe ComandoLerSenha.
ComandoLerSenha::ComandoLerSenha(Cpf cpf) {
    comandoSQL = "SELECT senha FROM conta WHERE cpf = '";
    comandoSQL += cpf.getValor();
    comandoSQL += "'";
}

string ComandoLerSenha::getResultado() {
        //Remover senha;
        if (listaResultado.empty()) {
            cout << "Lista de resultados vazia. Conteúdo da lista: " << endl;
            // Imprimir o conteúdo da lista para depuração
            for (const auto& elemento : listaResultado) {
                cout << "Nome da Coluna: " << elemento.getNomeColuna() << ", Valor da Coluna: " << elemento.getValorColuna() << endl;
            }
            throw EErroPersistencia("Lista de resultados vazia.");
        }
        ElementoResultado resultado = listaResultado.back();
        listaResultado.pop_back();

        return resultado.getValorColuna();
};

