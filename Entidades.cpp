#include "Entidades.h"

void Pagamento::setCodigo(const CodigoDePagamento& codigo) {
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
