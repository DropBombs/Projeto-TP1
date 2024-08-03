#include "FachadaTeste.h"
#include "Camada de Apresentação/ControladorasApr.h"
#include "Interfaces.h"

int main() {
    // Executando testes.
    FachadaTestes fachada;
    fachada.executarTestes();

    // Início do programa.
    cout << "Inicio do sistema CRUD." << endl;
    CntrlAAut cntrlAAut;
    Cpf cpf;
    cpf.setValor("529.982.247-25");

    if (cntrlAAut.autenticar(&cpf))
        cout << "Usuário autenticado com sucesso." << endl;
    else
        cout << "Falha na autenticação do usuário." << endl;

    return 0;
}
