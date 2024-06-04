#ifndef DOMINIOS_H
#define DOMINIOS_H
#include <iostream>
#include <stdexcept>
#include <regex>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

/// @file Dominios.h Arquivo contendo os Dominios requeridos.

/// @brief Declaracao de classe abstrata para interface e padronizacao da criacao de Dominios.
/// Uso de tipo string para uniformidade dos parametros.

class Dominio { // 190084499
public:
    virtual ~Dominio() = default; /// Metodo para validacao que pode lancar excecao a ser implementado pela classe herdada.
    /// @param valor Valor a ser validado antes de guardado.
    virtual void validar(string valor) = 0; /// Metodo para atribuicao de valor valido a ser implementado pela classe herdada.
    /// @param valor Valor a ser guardado.
    virtual void setValor(string valor) = 0; /// Metodo para obtencao do valor guardado a ser implementado pela classe herdada.
    /// @return Retorno do valor guardado.
    virtual string getValor() = 0;
};

// Declaracoes dos Dominios, utilizando herança.
/// Dominio requerido pelas especificacoes.

class Dinheiro : public Dominio { // 190084499
private:
    float dinheiroValue;
    static constexpr float LIMITE_INF = 0.00;
    static constexpr float LIMITE_SUP = 1000000.00;
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {
        ostringstream aux;
        aux << fixed << setprecision(2) << dinheiroValue;
        return aux.str();};
};

/// Dominio requerido pelas especificacoes.

class Percentual : public Dominio { // 190084499
private:
    int percentualValue;
    static constexpr unsigned short LIMITE_INF = 0;
    static constexpr unsigned short LIMITE_SUP = 100;
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {return to_string(percentualValue);};
};

/// Dominio requerido pelas especificacoes.

class CodigoDePagamento : public Dominio {
private:
        string codigoDePagamentoValue;
        static constexpr unsigned short TAMANHO = 8;
public:
        void validar(string valor) override;
        void setValor(string valor) override;
        string getValor() override {return codigoDePagamentoValue;};
};

/// Dominio requerido pelas especificacoes.

class CodigoDeTitulo : public Dominio {
private:
        string codigoDeTituloValue;
        static constexpr unsigned short TAMANHO = 11;
        static const char* siglasCodigosDeTitulo[];
public:
        void validar(string valor) override;
        void setValor(string valor) override;
        string getValor() override {return codigoDeTituloValue;};
};

/// Dominio requerido pelas especificacoes.

class Cpf : public Dominio {
private:
        string cpfValue;
        static constexpr unsigned short TAMANHO = 14;
public:
        void validar(string valor) override;
        void setValor(string valor) override;
        string getValor() override {return cpfValue;};
};

/// Dominio requerido pelas especificacoes.

class Data : public Dominio {
private:
        string dataValue;
        static const map<string, int>& getLimites() {
            static const map<string, int> limites = {
                {"diaMin", 1},
                {"diaMax", 31},
                {"mesMin", 1},
                {"mesMax", 12},
                {"anoMin", 2000},
                {"anoMax", 2100},
                {"diaMaxFevereiro", 28}
            };
            return limites;
        }
public:
        void validar(string valor) override;
        void setValor(string valor) override;
        string getValor() override {return dataValue;};
};

/// Dominio requerido pelas especificacoes.

class Estado : public Dominio { // 190084499
private:
    string estadoValue;
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {return estadoValue;};
};

/// Dominio requerido pelas especificacoes.

class Nome : public Dominio {
private:
    string nomeValue;
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {return nomeValue;};
};

/// Dominio requerido pelas especificacoes.

class Senha : public Dominio {
private:
    string senhaValue;
    static constexpr unsigned short TAMANHO = 6;
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {return senhaValue;};
};

/// Dominio requerido pelas especificacoes.

class Setor : public Dominio {
private:
    string setorValue;
    static const char* setores[];
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {return setorValue;};
};

#endif // DOMINIOS_H
