#include "Entidades.h"

/// Implementação dos métodos declarados pelas Entidades.

void Pagamento::setId() {
    Id = codigo.getValor();
};

void Pagamento::setCodigoPagamento(const CodigoDePagamento& codigo) {
    this->codigo = codigo;
};

void Pagamento::setData(const Data& data) {
    this->data = data;
};

void Pagamento::setPercentual(const Percentual& percentual) {
    this->percentual = percentual;
};

void Pagamento::setEstado(const Estado& estado) {
    this->estado = estado;
};

//---------------------------------------------------------------------------------------------------

void Titulo::setId() {
    Id = codigo.getValor();
};

void Titulo::setCodigoTitulo(const CodigoDeTitulo& codigo) {
    this->codigo = codigo;
};

void Titulo::setNome(const Nome& nome) {
    this->emissor = nome;
};

void Titulo::setSetor(const Setor& setor) {
    this->setor = setor;
};

void Titulo::setDataEmissao(const Data& data) {
    this->emissao = data;
};

void Titulo::setDataVencimento(const Data& data) {
    this->vencimento = data;
};

void Titulo::setDinheiro(const Dinheiro& valor) {
    this->valor = valor;
};
