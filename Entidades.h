#ifndef ENTIDADES_H
#define ENTIDADES_H
#include "Dominios.h"

class Pagamento {
private:
    CodigoDePagamento codigo;
    Data data;
    Percentual percentual;
    Estado estado;
public:
    void setCodigo(const CodigoDePagamento&);
    CodigoDePagamento getCodigo() const {return codigo;};
    void setData(const Data&);
    Data getData() const {return data;};
    void setPercentual(const Percentual&);
    Percentual getPercentual() const {return percentual;};
    void setEstado(const Estado&);
    Estado getEstado() const {return estado;};
};

#endif // ENTIDADES_H
