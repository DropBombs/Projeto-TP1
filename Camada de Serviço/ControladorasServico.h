#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED
#include "../Interfaces.h"

/// @file ControladorasServico.h Arquivo contendo as Controladoras da Camada de Servico.

/// Declaracao de classe Controladora que realize interface de Contas na Camada de Servico.
class CntrlSConta : public InterfaceSConta {
public:
    bool criar(Conta) override;
    bool recuperar(Conta*) override;
    bool atualizar(Conta) override;
    bool excluir(Cpf) override;
    vector<Conta> listarTodasContas();
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
