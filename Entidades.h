#ifndef ENTIDADES_H
#define ENTIDADES_H
#include "Dominios.h"

/// @file Entidades.h Arquivo contendo as Entidades requeridas.

/// Declaracao de classe abstrata para interface e padronizacao da criacao de Entidades.
// "Id" = identidade, definido como objeto identificador da classe.
// Por exemplo, o da Entidade Pagamento seria CodigoDePagamento.

class Entidade { // 190084499
public:
    virtual ~Entidade() = default; /// Metodo para atribuicao de identificador da Entidade.
    virtual void setId() = 0; /// Metodo para obtencao do identificador da Entidade.
    virtual string getId() = 0;
};

// Declaracoes das Entidades, utilizando heranca.
/// Entidade requerida, instanciando os Dominios definidos.

class Pagamento : public Entidade { // 190084499
private:
    CodigoDePagamento codigo;
    Data data;
    Percentual percentual;
    Estado estado;
    string Id;
public:
    void setId() override;
    string getId() override {return Id;};
    void setCodigoPagamento(const CodigoDePagamento&);
    CodigoDePagamento getCodigoPagamento() const {return codigo;};
    void setData(const Data&);
    Data getData() const {return data;};
    void setPercentual(const Percentual&);
    Percentual getPercentual() const {return percentual;};
    void setEstado(const Estado&);
    Estado getEstado() const {return estado;};
};

/// Entidade requerida, instanciando os Dominios definidos.

class Titulo : public Entidade { // 190084499
private:
    CodigoDeTitulo codigo;
    Nome emissor;
    Setor setor;
    Data emissao;
    Data vencimento;
    Dinheiro valor;
    string Id;
public:
    void setId() override;
    string getId() override {return Id;};
    void setCodigoTitulo(const CodigoDeTitulo&);
    CodigoDeTitulo getCodigoTitulo() const {return codigo;};
    void setNome(const Nome&);
    Nome getNome() const {return emissor;};
    void setSetor(const Setor&);
    Setor getSetor() const {return setor;};
    void setDataEmissao(const Data&);
    Data getDataEmissao() const {return emissao;};
    void setDataVencimento(const Data&);
    Data getDataVencimento() const {return vencimento;};
    void setDinheiro(const Dinheiro&);
    Dinheiro getDinheiro() const {return valor;};
};

/// Entidade requerida, instanciando os Dominios definidos.

class Conta : public Entidade { //200060422
private:
    Cpf cpf;
    Nome nome;
    Senha senha;
    string Id;
public:
    void setId() override;
    string getId() override {return Id;};
    void setCpf(const Cpf&);
    Cpf getCpf() const {return cpf;};
    void setNome(const Nome&);
    Nome getNome() const {return nome;};
    void setSenha(const Senha&);
    Senha getSenha() const {return senha;};
};

#endif // ENTIDADES_H
