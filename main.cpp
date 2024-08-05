#include "FachadaTeste.h"
#include "Camada de Apresentação/ControladorasApr.h"
#include "Interfaces.h"

int main() {

    // Executando testes.
    FachadaTestes fachada;
    fachada.executarTestes();

    // Início do programa.

    CntrlAprInicial();

    cout << "Obrigado pela preferencia.";

    return 0;
}
