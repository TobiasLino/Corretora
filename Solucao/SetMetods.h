#include <iostream>
#include <string>
#include "ClassDados.h"
#include "ClassOperations.h"
using namespace std;
/* 
    Arquivo com as definições dos métodos das funções
*/ 
/*
 

    CLASSES


*/
/*
    ********* Client ********    
*/
Cliente::Cliente(int q)
{
    quant = new int[q];
}
Cliente::~Cliente()
{
    delete[] quant;
}
void Cliente::setBasicInfo(string n, string p, string ec, string s, string pr, string dp, int *nasc, long cpf, long rg, long cnh)
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
void Cliente::setContact(char t[16], char e[80])
{
    telefone = t;
    email = e;
}
void Cliente::setAddress(char *r, char *b, char *com, char *cid, int n, long c)
{
    Rua = r;
    Bairro = b;
    Complemento = com;
    Cidade = cid;
    numero = n;
    CEP = c;
}
void Cliente::setPurchase(char *a, char *c, char *h, char *obs, char *indx, char *indxyz, char *rf, int r)
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
    cout    << "Nome: " << this->nome
            << "Pessoa(Física ou Jurídica): " << this->pessoa
            << "Estado Civil(C(asado), S(olteiro), D(ivorciado), V(iuvo)): " << this->EstadoCivil
            << "Sexo: " << this->sexo
            << "Data de Nascimento" << this->nascimento
            << "Profissão: " << this->profissao
            << "Documento Profissional: " << this->DocProf
            << "CPF ou CNPJ: " << this->CPF_CNPJ
            << "RG: " << this->RG
            << "CNH: " << this->CNH;
}
void Cliente::getContact()
{
    cout    << "Telefone: " << this->telefone
            << "Email: " << this->email;
}
void Cliente::getAddres()
{
    cout    << "Rua: " << this->Rua
            << "Número: " << this->numero
            << "Complemento: " << this->complemento
            << "Bairro: " << this->Bairro
            << "Cidade: " << this->Cidade
            << "CEP: " << this->CEP;
}
void Cliente::getPurchase()
{
    cout    << "Associação com a AMMG: " << this->AssociacaoAMMG
            << "Corretor: " << this->Corretor
            << "Histórico: " << this->Historico
            << "Renda" << this->Renda
            << "Observações" << this->Observacoes
            << "Indicação de: " << this->IndicacaoX
            << "Indicou: " << this->IndicouXYZ
            << "Relação Familiar com o indicado: " << this->RelacaoFamiliar;
}
/*
 * 
 * !!!!!!!!!!!!!!!!!!!11
 * 
 */
void Cliente::getFile()
{
    
}
void Cliente::getFullClient()
{
    getName();
    getContact();
    getAddress();
    getFile();
    getPurchase();
}
/*
 *  Corretor 
*/
Corretor::Corretor(int q)
{
    quant = new int[q];
}
Corretor::~Corretor()
{
    delete[] quant;
}
void Corretor::setBroker(char n[50], int t, long cpf)
{
    Nome = n;
    type = t;
    CPF_CNPJ = cpf;
}
void Corretor::setContact(char t, char e)
{
    telefone = t;
    email = e;
}
void Corretor::setAddres(char r, char b, char com, char cid, int n, long c){
    Rua = r;
    Bairro = b;
    Complemento = com;
    Cidade = cid;
    numero = n;
    CEP = c;
}
void Corretor::getName()
{
    cout    << "Nome: " << this->Nome
            << "Tipo de Usuário: " << this->type
            << "(1 - acesso completo, 2 - acesso apenas à visualização dos segurados vinculados, e 3 - visualização completa)"
            << "CPF/CNPJ: " << CPF_CNPJ
            << "Telefone: " << this->telefone
            << "Email: " << this->email;
}
void Corretor::getAddress()
{
    cout    << "Rua: " << this->Rua
            << "Número: " << this->numero
            << "Complemento: " << this->complemento
            << "Cidade: " << this->Cidade
            << "CEP: " << this->CEP;
}
void Corretor::getBroker()
{
    getName();
    getAddress();
}
/*
 * Produto
 */
Produto::produto(int q)
{
    quant = new int[q];
}
Produto::~produto()
{
    delete[] quant;
}
int SetID(int n)
{
    ID = n;
}
void Produto::setProduct(char s, char r, char n, char c, char v, char a, float com, int t)
{
    Seguradora = s;
    Ramo = r;
    nome = n;
    Corretor = c;
    Vigencia = v;
    Agenciamento = a;
    Comissao = com;
    Tipo = t;
}
void Produto::setValues(float p, float c, float cs , char V, char i, char obs)
{
    premio = p;
    comissionamento = c;
    capitalsegurado = cs;
    Veiculo = V;
    id = i;
    Observacoes = obs;
}
void Produto::setFile(char f)
{
    anexo = f;
}
void Produto::getProduct()
{
    cout    << "Seguradora: " << this->Seguradora
            << "Ramo: " << this->Ramo
            << "Nome: " << this->Nome
            << "Corretor: " << this->Corretor
            << "VIgencia: " << this->Vigencia
            << "Agenciamento: " << this->Agenciamento
            << "Comissão: " << this->Comissao
            << "Tipo: " << this->Tipo
            << "(seguro novo, renovação, endosso; mudança de endereço e capital segurado, etc)"
            << "Prêmio: " << this->premio
            << "Comissionamento: " << this->comissionamento
            << "Veiculo: " << this->Veiculo
            << "ID: " << this->id
            << "Observações: " << this->Observacoes;
}
/*  



 ********** Funções **********



*/
/* 
 *   Esta função realiza a chamada da função de criação de cliente,
 * nela o usuário define a quantidade de cliente que deseja adicionar,
 * assim a função é chamada com a quantidade desejada e cria n objetos.
 * 
*/
void setClientQuant()
{
    int n;
    cout    << "Quantos clientes deseja adicionar? " ; cin >> n;
    cout    << "Adicionando " << n << "Cliente(s)..."
            << "Insira os Dados do(s) cliente(s). " << endl;
    setNewClient(n);
}
/*
 *  Função que cria os novos n objetos de cliente e adiciona as informações dos atributos.
 *  O usuário insere os dados de forma sequencial, depois todos são inseridos dentro dos métodos 
 * da classe de cliente.
 * 
*/
void setNewClient(int vezes)
{
    // Dados a serem inseridos
    // Básico
    char    Nome[50], Pessoa[2], EC, Sex, Prof[80], DocProf[30];
    int     nascimento[3];
    long    CPF_CNPJ, RG, CNH;
    //      Contato
    char    Telefone[16], Email[80];
    //      Endereço
    char    Rua[50], Bairro[30], Complemento[20], Cidade[30];
    int     numero;
    long    CEP;
    //      Demais dados
    char    AssAMMG[20], Corr[50], Hist[80], Obs[80][10],
            IndicaX[50], IndicouXYZ[50][3], RelaFamiliar[10][3];
    // Ponteiros 
    char *n, *p, *pr, *dp;
    char *T, *E;
    char *R, *B, *C, *Cid;
    char *ammg, *cor, *H, *ob, *indx, *indxyz, *rela;
    int *naasc;
    // Setar a quantidade de Objetos a serem criados
    Cliente cli(vezes);
    // Variáveis internas
    int i=1, nasc=0;
    // Loop de Inserção
    do {
        // Instruções
        cout    << "Insira o Nome do Cliente " << i << ": " ; cin >> Nome;
        cout    << "Insira o tipo de Pessoa do Cliente " << i 
                << "PF(Pessoa Física) ou PJ(Pessoa Jurídica). " << ": " ; cin >> Pessoa;
        cout    << "Insira o Estado Civil do Cliente " << i << ": "; cin >> EC;
        cout    << "Insira o Sexo do Cliente " << i << " M(asculino) ou F(eminino). " << ": " ; cin >> Sex;
        cout    << "Insira a Profissão do Cliente " << i << ": " ; cin >> Prof;
        cout    << "Insira a data de nascimento do cliente " << i ; cout << "Dia: " ; cin >> nascimento[nasc] ; cout << " Mês: " ; cin >> nascimento[nasc++] ; cout << " Ano: " ; cin >> nascimento[nasc++]; 
        cout    << "Insira o CPF ou CNPJ do Cliente " << i << " : " ; cin >> CPF_CNPJ;
        cout    << "Insira o Telefone do Cliente " << i << " : " ; cin >> Telefone;
        cout    << "Insira o Email do Cliente " << i << " : " ; cin >> Email;
        // Ponteiro adquire o endereço das matrizes
        n = Nome; p = Pessoa; pr = Prof; dp = DocProf;
        T = Telefone; E = Email;
        R = Rua; B = Bairro; C = Complemento; Cid = Cidade;
        ammg = AssAMMG; cor = Corr; H = Hist; ob = Obs; indx = IndicaX; indxyz = IndicouXYZ; rela = RelaFamiliar;

        // Inserção dentro dos objetos
        cli.setBasicInfo(n, p, EC, Sex, pr, dp, naasc, CPF_CNPJ, RG, CNH);
        cli.setContact(T, E);
        cli.setAddress(R, B, C, Cid, numero, CEP);
        // Iteração
        i++;
    } while(i<=vezes);
}
/* 
 *   Esta função realiza a chamada da função de criação de ccorretor,
 * nela o usuário define a quantidade de corretores que deseja adicionar,
 * assim a função é chamada com a quantidade desejada e cria n objetos.
 * 
*/
void setBrokerQuant()
{
    int n;
    cout    << "Insira a quantidade de Corretores que serão adicionados: " ; cin >> n;
    cout    << "Adicionando " << n << "Corretores..." << endl;
    cout    << "Insira os dados do(s) Corretor(s). " << endl;
    setNewBroker(n);
}
/*
 *  Função que cria os novos n objetos de Corretor e adiciona as informações nos atributos.
 *  O usuário insere os dados de forma sequencial, depois todos são inseridos dentro dos métodos 
 * da classe de Corretor.
 * 
*/
void setNewBroker(int vezes)
{

}

/* 
 *   Esta função realiza a chamada da função de criação de Produto,
 * nela o usuário define a quantidade de Produtos que deseja adicionar,
 * assim a função é chamada com a quantidade desejada e cria n objetos.
 * 
*/
void setProductQuant()
{
    int n;
    cout    << "Insira a quantidade de produtos que serão adicionados: " ; cin << n;
    cout    << "Adicionando " << n << "Produto(s)..." << endl;
    cout    << "insira os dados do(s) produto(s)." << endl;
    setNewProduct(n);
}
/*
 *  Função que cria os novos n objetos de Produto e adiciona as informações dos atributos.
 *  O usuário insere os dados de forma sequencial, depois todos são inseridos dentro dos métodos 
 * da classe de Produto.
 * 
*/
void setNewProduct(int vezes)
{

}
