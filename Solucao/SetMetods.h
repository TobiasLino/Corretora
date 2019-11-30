/**
 * @autor <TOBIAS DA SILVA LINO>
 * @brief Arquivo com as definições dos métodos das funções
 * @details 
 *  Modifica o que cada método faz dentro das funções, foi criado neste arquivo
 *  com o objetivo de focar no mais importante dentro do arquivo de classes principal.
 */
#include <iostream>
#include <string>
#include <list>
#include "ClassDados.h"
using namespace std;
/**
 *  @brief Classe contendo a construção do Endereço
 */
ENDERECO::ENDERECO(string r = "", string b = "", string com = "", string cid = "", int n = 0, long c = 0)   /// cria a instância com valores default
{
    /** @details
     *  Constroi a instancia ENDERECO com valores default nulos
     *  onde o sistema irá carregá-los na memória
     * @param ENDERECO     Construtor principal
     * @param rua          Rua a ser inserida
     * @param Bairro       Bairro a ser inserido
     * @param Complemento  Complemento, se houver
     * @param Cidade       Cidade a ser inserida
     * @param numero       Numero da casa
     * @param CEP          CEP da Rua
     * @return             Constroi uma instancia da classe ENDERECO com os parametros passados
    */
    Rua = r;
    Bairro = b;
    Complemento = com;
    Cidade = cid;
    numero = n;
    CEP = c;
}
void ENDERECO::getAddress()
{
    cout    << "Rua: " << Rua << endl
            << "Bairro: " << Bairro << endl
            << "Complemento: " << Complemento << endl
            << "Cidade: " << Cidade << endl
            << "Número: " << numero << endl
            << "CEP: " << CEP << endl;
}
/**
    ********** PEDIDO **********
*/
PEDIDO::PEDIDO(CLIENTE cl, CORRETOR co, PRODUTO po)
{
    this.cliente = cl;
    this.corretor = co;
    this.produto = po;
}
/**
    ********* Client ********    
*/
/// Construtor
CLIENTE::CLIENTE(string n = "", string p = "", string ec = "", string s = "", string pr = "", string dp = "", int* nasc=0, long cpf = 0, long rg = 0, long CNH = 0)   /// cria a instância com valores default
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
/**
    métodos set
*/
void CLIENTE::setAddress(string r = "", string b = "", string com = "", string cid = "", int n = 0, long c = 0)   /// cria a instância com valores default
{
    ENDERECO *ptr;
    ptr = &this.endereco;
    ptr->Rua = r;
    ptr->Bairro = b;
    ptr->Complemento = com;
    ptr->Cidade = cid;
    ptr->numero = n;
    ptr->CEP = c;
}
void CLIENTE::setContact(string t = "", string e = "")   /// cria a instância com valores default
{
    telefone = t;
    email = e;
}
void CLIENTE::setPurchase(string a = "", string c = "", string h = "", string obs = "", string indx = "", string indxyz = "", string rf = "", int r = 0)    // cria a instância com valores default
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
void CLIENTE::setFile(string nameFile = "")
{
    FILE anexo, *ptr;
    ptr = &anexo;
    ptr->Name = nameFile;
}
/*
    Métodos get
*/
void CLIENTE::getName()
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
void CLIENTE::getContact()
{
    cout    << "Telefone: " << this->telefone
            << "Email: " << this->email;
}
void CLIENTE::getAddres()
{
    cout    << "Rua: " << this->Rua
            << "Número: " << this->numero
            << "Complemento: " << this->complemento
            << "Bairro: " << this->Bairro
            << "Cidade: " << this->Cidade
            << "CEP: " << this->CEP;
}
void CLIENTE::getPurchase()
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
void CLIENTE::getFile()
{
    
}
void CLIENTE::getFullClient()
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
// Construtor
CORRETOR::CORRETOR(string n="", int t=0, long cpf=0)    // cria a instância com valores default 
{
    Nome = n;
    type = t;
    CPF_CNPJ = cpf;
}
/*
    métodos set
*/
void CORRETOR::setContact(char t, char e)
{
    telefone = t;
    email = e;
}
void CORRETOR::setAddres(char r, char b, char com, char cid, int n, long c)
{
    ENDERECO *ptr;
    ptr = &this.endereco;
    ptr->Rua = r;
    ptr->Bairro = b;
    ptr->Complemento = com;
    ptr->Cidade = cid;
    ptr->numero = n;
    ptr->CEP = c;
}
/*
    métodos get
*/
void CORRETOR::getName()
{
    cout    << "Nome: " << this->Nome
            << "Tipo de Usuário: " << this->type
            << "(1 - acesso completo, 2 - acesso apenas à visualização dos segurados vinculados, e 3 - visualização completa)"
            << "CPF/CNPJ: " << CPF_CNPJ
            << "Telefone: " << this->telefone
            << "Email: " << this->email;
}
void CORRETOR::getAddress()
{
    cout    << "Rua: " << this->Rua
            << "Número: " << this->numero
            << "Complemento: " << this->complemento
            << "Cidade: " << this->Cidade
            << "CEP: " << this->CEP;
}
void CORRETOR::getBroker()
{
    getName();
    getAddress();
}
/*
 * Produto
 */
PRODUTO::PRODUTO(int q)
{
    quant = new int[q];
}
int SetID(int n)
{
    ID = n;
}
void PRODUTO::setProduct(char s, char r, char n, char c, char v, char a, float com, int t)
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
void PRODUTO::setValues(float p, float c, float cs , char V, char i, char obs)
{
    premio = p;
    comissionamento = c;
    capitalsegurado = cs;
    Veiculo = V;
    id = i;
    Observacoes = obs;
}
void PRODUTO::setFile(char f)
{
    anexo = f;
}
void PRODUTO::getProduct()
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

/*
    ********** DATA *********

    Constrói uma classe com formato de data
    dia está como inteiro, os meses estão em formato enumerado, e o ano está como inteiro também
    Será a classe que fará o formato para a classe prestação e calendário.

*/
DATA::DATA(int d = 0,Mes m, int a = 0)
{
    dia = d;
    mes = m;
    ano = a;
}
/*
    Operador pra poder realizar opções como cout << data << endl;
*/
ostream& operator<<(ostream& out, DATA &data)
{
    out << "Dia: " << data.dia << ", Mes: " << data.mes << ", ano: " << data.ano;
    return out;
}
/*
    ********** PRESTAÇÕES *********

    Constrói uma classe que definirá as prestações do produto vendido
    uma para cada mês de acordo com a classes data

*/
PRESTACAO::PRESTACAO(PEDIDO prod)
{
    prestation = prod.getPrestation();
}
/*
    Define qual o dia da primeira prestação
*/
void PRESTACAO::setBegin(int d, Mes m, int a)
{
   dataInicio = new DATA(d,m,a);
}
/*
    Define o dia da última prestação
*/
void PRESTACAO::setEnd(int d, Mes m, int a)
{
    dataFinal = new DATA(d,m,a);
}
/*
    Imprime todas as prestações
*/
void PRESTACAO::getAllPrestations()
{
    int i=0;        // variável de iteração
    DATA *proxima;     // ponteiro para a próxima prestação
    proxima = &dataInicio;  // recebe a primeira prestação
    for(i=0;i<=prestation;i++)  // calcula a quantidade de prestações
    {
        // usa um método de excessões para retornar se a operação funcionou
        try {
            cout << proxima << endl;    // imprime a primeira data
            if(dataInicio.getMonth() >12) {                                                                               //  faz a verificação de ano, se o mês passar de 12
                proxima = new DATA(dataInicio.getDay(), dataInicio.getMonth()=Janeiro, dataInicio.getYear()+1); }         //  adiciona um ano ao ponteiro proxima
            else { proxima = new DATA(dataInicio.getDay(), dataInicio.getMonth()+1, dataInicio.getYear()); }              //  ccertifica que os meses estarão aumentando
        }                                                                                                       
        catch {
            cout << "Erro " << endl;       // retorna a mensagem de erro para o terminal
        }   
    }
    delete proxima;         // finaliza o método destruindo o ponteiro proxima
}
/*
    Imprime a primeira 
*/
void PRESTACAO::getBegin()
{
    cout << dataInicio << endl;
}
/*
    Imprime a última
*/
void PRESTACAO::getEnd()
{
    cout << dataFinal << endl;
}