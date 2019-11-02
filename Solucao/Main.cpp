#include <iostream>
/*
 * Classe de Dados do Cliente
 */
class Client {
    public:
        cliente(int);
        ~cliente();
        void setBasicInfo(char, char, char, char, char, char, int, long, long, long);
        void setContact(char, char);
        void setAddress(char, char, char, char, int, long);
        void setPurchase(char, char, char, char, char, char, char, int);
        void setFile(char);
        void getName();
        void getContact();
        void getAddres();
        void getPurchase();
        void getFullClient();
    private:
        int *quant;
        // Informações Básicas
        char nome[50];
        char pessoa[2];
        char EstadoCivil;      // C(asado), S(olteiro), D(ivorciado), V(iuvo)
        char sexo;          // M ou F
        char profissao[80];
        char DocProf[80];
        int nascimento[3];
        long CPF_CNPJ;
        long RG;
        long CNH;
        // Contato
        char telefone[14];
        char email[80];
        // Endereço
        char Rua[50];
        char Bairro[30];
        char complemento[20];
        char Cidade[30];
        int numero;
        long CEP;
        // Demais dados
        char AssociacaoAMMG[20];
        char Corretor[50];
        char Historico[80];
        char Observacoes[80][10];
        char IndicacaoX[50];
        char IndicouXYZ[50][3];
        char RelacaoFamiliar[10][3];
        int Renda;
        // Anexo
        char Anexo[20];
};
/*
 * Classe de Dados do Corretor
 */
class Corretor {
    public:
        corretor();
        ~corretor();
        void setBroker(char, int, long);
        void setContact(char, char);
        void setAddres(char, char, char, char, int, long);
        void getName();
        void getAddress();
        void getBroker();
    private:
        int *quant;
        // Informações Básicas
        char Nome[50];
        int type;
        long CPF_CNPJ;
        // Contato
        char email[80];
        char telefone[14];
        // Endereço
        char Rua[50];
        char Bairro[30];
        char complemento[20];
        char Cidade[30];
        int numero;
        long CEP;
};
/*
 * Classe de Dados de Produto
 */
class Produto {
    public:
        produto(int);
        ~produto();
        void setProduct(char, char, char, char, char, char, float, int);
        void setValues(float, float, float, char, char, char);
        void setFile(char);
        void getProduct();
    private:
        int ID;
        int *quant;
        // Informações Básicas
        char Seguradora[20];
        char Ramo[20];
        char Nome[50];
        char Corretor[50];
        char Vigencia[50];
        char Agenciamento[20];
        float Comissao;
        int Tipo;
        // Valores
        float premio;
        float comissionamento;
        float capitalsegurado;
        char Veiculo[30];
        char ID[20];
        char Observacoes[80][10];
        // Anexo
        char anexo[20];
};
/*
 * Classe de Dados de Usuário
 */
class Usuario {
    public:
        User(int);
        ~User();
        void setUser(char, int);
        void getUser();
    private:
        int ID;
        int *quant;
        // Basic
        char Nome[20];
        int id;
};
/*
 * Classe de Dados de Relatório
 */
class Relatorio {
    public:
        relatorio(int);
        ~relatorio();
        // char getResume();
        void setProductionRel(int, char, char, float, float, float, float, float, float);
        void setPRtoAMMg();
        void getRel();
    private:
        int *quant;
        // Basic
        int periodo[3];
        char ClientInic[6];
        char Ramo[20];
        float ValorParcela;
        float comissao;
        float AMMGpercent;
        float ValorsemDeduc;
        float Deduc;
        float Repasse;
};
/*
 * Classe de Dados Para Filtros nas Pesquisas
 */
class Filtro {
    public:
        filtro(int);
        ~filtro();
        void setFilters(char, char, char, int, long);
    private:
        int *quant;
        // Filtros
        char PNome[50];
        char Pemail[50];
        char Pseguro[30];
        int Pidade;
        long PCPF;
};
/* 
 * Classe de Acesso ao Calendário
 */
class Calendario {
    public:
        void AdicionarPagamento(int, float);
        void ImprimirPagamentos(int[]);
    private:
        int Acess;  // Define o tipo de acesso 0 ou 1
};
/* 
 * Classe de Operações de Telemarketing
 */
class Telemarketing {
    public:
        void Autosend();
        void SendEmail();
        void SelectClient();
    private:
        char Sender[30];
        char Recipient[30];
        char Conteudo[20];      // File
};
/*
 * Classes e Seus respectivos métodos
 *
 *  
 * Client */
Cliente::cliente(int q)
{
    quant = new int[q];
}
Cliente::~cliente()
{
    delete[] quant;
}
void Cliente::setBasicInfo(char n[50], char p[2], char ec, char s, char pr[80], char dp[80], int nasc, long cpf, long rg, long cnh)
{
    nome = n;
    pessoa = p;
    EstadoCivil = ec;
    sexo = s;
    profissao = pr;
    DocProf = dp;
    nascimento = nasc;
    CPF_CNPJ = cpf;
    RG = rg;
    CNH = cnh;
}
void Cliente::setContact(char t[14], char e[80])
{
    telefone = t;
    email = e;
}
void Cliente::setAddress(char r[50], char b[30], char com[20], char cid[30], int n, long c)
{
    Rua = r;
    Bairro = b;
    Complemento = com;
    Cidade = cid;
    numero = n;
    CEP = c;
}
void Cliente::setPurchase(char a[20], char c[50], char h[80], char obs[80][10], char indx[50], char indxyz[50][3], char rf[10][3], int r)
{
    AssociacaoAMMG = a;
    Corretor = c;
    Historico = h;
    Observacoes = obs;
    IndicacaoX = indx;
    IndicouXYZ = indxyz;
    RelacaoFamiliar = rf;
    Renda = r;
}
void Cliente::setFile(char nameFile)
{
    Anexo = fopen(nameFile);
    if(Anexo)
        cout << "Arquivo Aberto. " << endl;
    else
        cout << "Arquivo inexistente. " << endl;
    
}
void Cliente::getName()
{

}
void Cliente::getContact()
{

}
void Cliente::getAddres()
{

}
void Cliente::getPurchase()
{

}
void Cliente::getFullClient()
{

}
