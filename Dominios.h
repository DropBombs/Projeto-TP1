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

/// Declaração de classe abstrata para interface de criação de dominios.
/// Utilização de tipo string para padronização da interface.

class Dominio {
public:
    virtual ~Dominio() = default;
    virtual void validar(string valor) = 0;
    virtual void setValor(string valor) = 0;
    virtual string getValor() = 0;
};

/// Declarações dos dominios, utilizando herança.

class Dinheiro : public Dominio {
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

class Percentual : public Dominio {
private:
    int percentualValue;
    static constexpr unsigned short LIMITE_INF = 0;
    static constexpr unsigned short LIMITE_SUP = 100;
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {return to_string(percentualValue);};
};

class CodigoDePagamento : public Dominio {
private:
        string codigoDePagamentoValue;
        static constexpr unsigned short TAMANHO = 8;
public:
        void validar(string valor) override;
        void setValor(string valor) override;
        string getValor() override {return codigoDePagamentoValue;};
};

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

class Cpf : public Dominio {
private:
        string cpfValue;
        static constexpr unsigned short TAMANHO = 14;
public:
        void validar(string valor) override;
        void setValor(string valor) override;
        string getValor() override {return cpfValue;};
};

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

class Estado : public Dominio {
private:
    string estadoValue;
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {return estadoValue;};
};

class Nome : public Dominio {
private:
    string nomeValue;
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {return nomeValue;};
};

class Senha : public Dominio {
private:
    string senhaValue;
    static constexpr unsigned short TAMANHO = 6;
public:
    void validar(string valor) override;
    void setValor(string valor) override;
    string getValor() override {return senhaValue;};
};

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
