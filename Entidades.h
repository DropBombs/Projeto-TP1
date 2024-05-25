#ifndef ENTIDADES_H
#define ENTIDADES_H
#include "Dominios.h"

/// Declaração de interface para padronização de Entidades.
/// "Id" = identidade, definido como objeto identificador da classe.
/// Por exemplo, o da entidade Pagamento seria Código de Pagamento.

class Entidade {
public:
    virtual ~Entidade() = default;
    virtual void setId() = 0;
    virtual string getId() = 0;
};

class Pagamento : public Entidade {
private:
    CodigoDePagamento codigo;
    Data data;
    Percentual percentual;
    Estado estado;
    string Id;
public:
    void setId() override;
    string getId() override {return Id;};
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
