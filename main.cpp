#include "Dominios.h"
#include "Teste.h"
#include "Entidades.h"

using namespace std;

/// Funções para criação e teste dinâmicos dos domínios.

/// Função que mapeia o nome do dominio a um ponteiro para ele.

Dominio* criarDominio(const string& tipo) {
    map<string, function<Dominio*()>> fabricaDominios = {  /// Mapeia string a uma função lambda de criação de ponteiro.
        {"Dinheiro", []() {return new Dinheiro();}},
        {"Percentual", []() {return new Percentual();}},
        {"CodigoDePagamento", []() {return new CodigoDePagamento();}},
        {"CodigoDeTitulo", []() {return new CodigoDeTitulo();}},
        {"Cpf", []() {return new Cpf();}},
        {"Data", []() {return new Data();}},
        {"Estado", []() {return new Estado();}}
        /// Adicionar outros dominios.
    };

    auto aux = fabricaDominios.find(tipo); /// Procura o dominio desejado.
    if (aux != fabricaDominios.end()) {    /// Checa se foi encontrado o dominio.
        return aux->second();              /// Se sim, retorna o ponteiro criado.
    } else {
        cout << "Dominio não encontrado." << endl;
        return nullptr;                   /// Se não, retorna ponteiro nulo.
    };
};

/// Criação de Teste de Unidade baseado no Dominio escolhido.

UnidadeTeste* criarUnidadeTeste(Dominio* dominio) {
    if (dynamic_cast<Dinheiro*>(dominio))
        return new UTMonetario(dominio);
    else if (dynamic_cast<Percentual*>(dominio))
        return new UTPercentual(dominio);
    else if (dynamic_cast<CodigoDePagamento*>(dominio))
        return new UTCdPagamento(dominio);
    else if (dynamic_cast<CodigoDeTitulo*>(dominio))
        return new UTCdTitulo(dominio);
    else if (dynamic_cast<Cpf*>(dominio))
        return new UTCPF(dominio);
    else if (dynamic_cast<Data*>(dominio))
        return new UTData(dominio);
    else if (dynamic_cast<Estado*>(dominio))
        return new UTEstado(dominio);
    else
        return nullptr;
};

/// Teste automatizado, que chama executar da classe teste fornecida.

bool autoTeste(Dominio* testeDominio, UnidadeTeste* testeUnidade) {
    if (!testeDominio || !testeUnidade)
        return false;

    switch (testeUnidade->executar()) {
        case testeUnidade->FALHA:
            return false;
        case testeUnidade->SUCESSO:
            return true;
        default:
            return false;
    }
};

/// Loop para execução de testes em um conjunto de dominios, que termina o programa se falhar.

void bateriaTestes(const vector<string>& tipoDominio) {
    for (const auto& tipo : tipoDominio) {
        Dominio* dominio = criarDominio(tipo);
        UnidadeTeste* testeUnidade = criarUnidadeTeste(dominio);
        bool retorno = autoTeste(dominio, testeUnidade);
        if (retorno) {
            cout << "Sucesso na inicialização de " << tipo << "." << endl;
        } else {
            cout << "Falha nos testes iniciais de " << tipo << ". Encerrando..." << endl;
            exit(-1);
        }
        delete dominio;
    }
    cout << "Começando operações..." << endl;
};

/// Inicializando os testes e um exemplo de uso.

int main() {
    Pagamento pagamento;
    Estado estado;
    vector<string> dominiosTeste = {"Dinheiro", "Percentual", "CodigoDePagamento", "CodigoDeTitulo", "Cpf", "Data", "Estado"};
    bateriaTestes(dominiosTeste);

    estado.setValor("Previsto");
    pagamento.setEstado(estado);
    cout << pagamento.getEstado().getValor();

    return 0;
}
