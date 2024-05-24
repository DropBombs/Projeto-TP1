#include "Dominios.h"

/// Implementa��o das fun��es set e validar, onde validar pode lan�ar exce��o.

void Dinheiro::setValor(string valor) {
    validar(valor);
    this->dinheiroValue = stof(valor);
};

void Dinheiro::validar(string valor) {
    float fvalor = stof(valor);
    if (fvalor > LIMITE_SUP || fvalor < LIMITE_INF)
            throw invalid_argument("Valor inv�lido.");
};

//---------------------------------------------------------------------------------------------------

void Percentual::setValor(string valor) {
    validar(valor);
    this->percentualValue = stoi(valor);
};

void Percentual::validar(string valor) {
    int ivalor = stoi(valor);
    if (ivalor > LIMITE_SUP || ivalor < LIMITE_INF)
        throw invalid_argument("Valor inv�lido.");
};

//---------------------------------------------------------------------------------------------------

void CodigoDePagamento::setValor(string valor) {
    validar(valor);
    this->codigoDePagamentoValue = valor;
};

void CodigoDePagamento::validar(string valor) {
    if (valor.size() < TAMANHO || valor.size() > TAMANHO)
        throw invalid_argument("Tamanho do c�digo inv�lido. Deve ter exatamente 8 d�gitos.\n");

    if (valor[0] == '0')
        throw invalid_argument("Primeiro d�gito do c�digo n�o pode ser 0.\n");

    for (int i = 0; i < TAMANHO; i++) {
        if (valor[i] < '0' || valor[i] > '9')
            throw invalid_argument("Formato errado, somente digitos sao permitidos.\n");
    };
};

//---------------------------------------------------------------------------------------------------

const char* CodigoDeTitulo::siglasCodigosDeTitulo[] = {"CDB", "CRA", "CRI", "LCA", "LCI", "DEB"};

void CodigoDeTitulo::setValor(string valor) {
    validar(valor);
    this->codigoDeTituloValue = valor;
};

void CodigoDeTitulo::validar(string valor) {
    if (valor.size() < TAMANHO || valor.size() > TAMANHO)
        throw invalid_argument("Tamanho do c�digo inv�lido. Deve ter exatamente 11 d�gitos (YYYXXXXXXXX).\n");

    string siglaDoCodigoDeTitulo = valor.substr(0, 3);
    bool valido = false;
    for (const char* sigla : siglasCodigosDeTitulo) {
        if (sigla == siglaDoCodigoDeTitulo) {
            valido = true;
            break;
        }
    }

    if (!valido)
        throw invalid_argument("Sigla de c�digo de t�tulo inv�lida.\n");

    for (size_t i = 3; i < TAMANHO; i++) {
        if (!((valor[i] >= 'A' && valor[i] <= 'Z') || (valor[i] >= '0' && valor[i] <= '9')))
            throw invalid_argument("Formato errado, somente digitos ou letras s�o permitidos.\n");
    }
};

//---------------------------------------------------------------------------------------------------

void Cpf::setValor(string valor) {
    validar(valor);
    this->cpfValue = valor;
};

void Cpf::validar(string valor) {
    if (valor.size() < TAMANHO || valor.size() > TAMANHO)
        throw invalid_argument("Tamanho do CPF inv�lido");

    regex formatoCpf("^\\d{3}\\.\\d{3}\\.\\d{3}-\\d{2}$");

    if (!regex_match(valor, formatoCpf))
        throw invalid_argument("Formato do CPF inv�lido");

    valor.erase(remove_if(valor.begin(), valor.end(), [](char c) { return c == '.' || c == '-'; }), valor.end());
    int soma = 0;
    int multiplicador = 10;
    for (int i = 0; i < 9; ++i) {
        soma += (valor[i] - '0') * multiplicador;
        --multiplicador;
    }
    int resto = soma % 11;
    int primeiroDigito = (resto < 2) ? 0 : 11 - resto;

    soma = 0;
    multiplicador = 11;
    for (int i = 0; i < 10; ++i) {
        soma += (valor[i] - '0') * multiplicador;
        --multiplicador;
    }
    resto = soma % 11;
    int segundoDigito = (resto < 2) ? 0 : 11 - resto;

    if ((valor[9] - '0'!= primeiroDigito) || (valor[10] - '0' != segundoDigito))
        throw invalid_argument("CPF inv�lido.");
};

//---------------------------------------------------------------------------------------------------

void Data::setValor(string valor) {
    validar(valor);
    this->dataValue = valor;
};

void Data::validar(string valor) {
    regex formatoData(R"((\d{2})-(\d{2})-(\d{4}))");
    smatch match;

    if (!regex_match(valor, match, formatoData))
        throw invalid_argument("Formato da data inv�lido. Esperado: DD-MM-AAAA.");

    const map<string, int>& limites = getLimites();
    int tamanhoData = valor.size();

    if (tamanhoData < 0)
        throw invalid_argument("Nenhuma data foi inserida.");

    if (tamanhoData > 10)
        throw invalid_argument("Data muito extensa.");

    int dia = stoi(match[1].str());
    int mes = stoi(match[2].str());
    int ano = stoi(match[3].str());

    if (dia < limites.at("diaMin") || dia > limites.at("diaMax"))
        throw invalid_argument("Dia inv�lido.");

    if (mes < limites.at("mesMin") || mes > limites.at("mesMax"))
        throw invalid_argument("M�s inv�lido.");

    if (ano < limites.at("anoMin") || ano > limites.at("anoMax"))
        throw invalid_argument("Ano inv�lido.");

    bool anoBissexto = false;
    if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
        anoBissexto = true;

    if (mes == 2) {
        int maxDia = anoBissexto ? 29 : limites.at("diaMaxFevereiro");
        if (dia < limites.at("diaMin") || dia > maxDia)
            throw invalid_argument("Dia inv�lido para o m�s de fevereiro.");
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30)
        throw invalid_argument("Dia inv�lido para o m�s.");
};

//---------------------------------------------------------------------------------------------------

void Estado::setValor(string valor) {
    validar(valor);
    this->estadoValue = valor;
};

void Estado::validar(string valor) {
    if (valor != "Previsto" && valor != "Liquidado" && valor != "Inadimplente")
        throw invalid_argument("Estado da conta inv�lido.");
};
