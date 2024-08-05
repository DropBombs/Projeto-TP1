#ifndef FABRICAS_H
#define FABRICAS_H
#include <string>
#include <functional>
#include "Teste.h"

using namespace std;

/// @file Fabricas.h Arquivo contendo classe para construcao de Dominios.

/// Declaracao de classe para criacao de Dominios.
class Fabricas {
public:
    static Dominio* criarDominios(const string&); // Funcao que mapeia o nome do Dominio a um ponteiro para ele.
    static UnidadeTeste* criarUnidadeTeste(Dominio*);
};

inline Dominio* Fabricas::criarDominios(const string& tipo) {
    map<string, function<Dominio*()>> fabricaDominios = {  // Mapeia string a uma função lambda de criação de ponteiro.
        {"Dinheiro", []() {return new Dinheiro();}},
        {"Percentual", []() {return new Percentual();}},
        {"CodigoDePagamento", []() {return new CodigoDePagamento();}},
        {"CodigoDeTitulo", []() {return new CodigoDeTitulo();}},
        {"Cpf", []() {return new Cpf();}},
        {"Data", []() {return new Data();}},
        {"Estado", []() {return new Estado();}},
        {"Nome", []() {return new Nome();}},
        {"Senha", []() {return new Senha();}},
        {"Setor", []() {return new Setor();}}
    };

    auto aux = fabricaDominios.find(tipo); // Procura o dominio desejado.
    if (aux != fabricaDominios.end()) {    // Checa se foi encontrado o dominio.
        return aux->second();              // Se sim, retorna o ponteiro criado.
    } else {
        cout << "Dominio não encontrado." << endl;
        return nullptr;                   // Se não, retorna ponteiro nulo.
    };
};

inline UnidadeTeste* Fabricas::criarUnidadeTeste(Dominio* dominio) {
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
    else if (dynamic_cast<Nome*>(dominio))
        return new UTNome(dominio);
    else if (dynamic_cast<Senha*>(dominio))
        return new UTSenha(dominio);
    else if (dynamic_cast<Setor*>(dominio))
        return new UTSetor(dominio);
    else
        return nullptr;
};

#endif // FABRICAS_H
