/*
 * CORRETORA DE SEGUROS
 * 
 * Aqui se encontra a solução para um sistema de corretora de seguros, onde é necessário realizar o cadastro
 *  dos clientes, dos produtos e dos corretores. Também é necessário gerar relatórios, realizar pesquisas com filtros,
 *  gerenciar operações com calendário(verificar os pagamentos do dia selecionado etc.) e realizar operações de telemarketing(envio de emails programado).
 * 
 * !!!!!!!!!!!!!1É necessário salvar os dados inseridos em um arquivo.!!!!!!!!!!!!!!
*/
#include <iostream>
using namespace std;
/*
 * Classe de Dados do Cliente
 */
class Cliente {
    public:
        Cliente(int);
        ~Cliente();
        void setBasicInfo(char*, char*, char, char, char*, char*, int*, long, long, long);
        void setContact(char*, char*);
        void setAddress(char*, char*, char*, char*, int, long);
        void setPurchase(char*, char*, char*, char*, char*, char*, char*, int);
        void setFile(char*);
        void getName();
        void getContact();
        void getAddres();
        void getPurchase();
        void getFIle();
        void getFullClient();
        // Exceções
        class IndexException {
            public:
                int index;
                IndexException(int n) : indice(n) {}
        };
        int & operator[](int n) {
            if(n<0 || n>=quant) throw IndexException(n);
            return quant[n];
        }
        class EmptyInfoException {};
        class EmptyContactException {};
        class EmptyAddressException {};
        class EmptyPurchaseException {};
        class _ERROR_getInfos {};
    private:
        int *quant;
        // Informações Básicas
        char nome[50];
        char pessoa[2];
        char EstadoCivil;   // C(asado), S(olteiro), D(ivorciado), V(iuvo)
        char sexo;          // M ou F
        char profissao[80];
        char DocProf[30];
        int nascimento[3];
        long CPF_CNPJ;
        long RG;
        long CNH;
        // Contato
        char telefone[16];
        char email[80];
        // Endereço
        char Rua[50];
        char Bairro[30];
        char Complemento[20];
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
        Corretor(int);
        ~Corretor();
        void setBroker(char, int, long);
        void setContact(char, char);
        void setAddres(char, char, char, char, int, long);
        void getName();
        void getAddress();
        void getBroker();// Exceções
        class IndexException {
            public:
                int index;
                IndexException(int n) : indice(n) {}
        };
        int & operator[](int n) {
            if(n<0 || n>=quant) throw IndexException(n);
            return quant[n];
        }
        class EmptyInfoException {};
        class EmptyContactException {};
        class EmptyAddressException {};
        class InexFileException {};
        class CorruptedFileException {};
        class _ERROR_getInfos {};
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
        char Complemento[20];
        char Cidade[30];
        int numero;
        long CEP;
};
/*
 * Classe de Dados de Produto
 */
class Produto {
    public:
        Produto(int);
        ~Produto();
        int setID(int);
        void setProduct(char, char, char, char, char, char, float, int);
        void setValues(float, float, float, char, char, char);
        void setFile(char);
        void getProduct();// Exceções
        class IndexException {
            public:
                int index;
                IndexException(int n) : indice(n) {}
        };
        int & operator[](int n) {
            if(n<0 || n>=quant) throw IndexException(n);
            return quant[n];
        }
        class EmptyInfoException {};
        class EmptyValueException {};
        class InexFileException {};
        class CorruptedFileException {};
        class _ERROR_getInfos {};
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
        char id[20];
        char Observacoes[80][10];
        // Anexo
        char anexo[20];
};
/*
 * Classe de Dados de Relatório
 */
class Relatorio {
    public:
        Relatorio(int);
        ~Relatorio();
        void setResume();
        void getResume();
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
        Filtro(int);
        ~Filtro();
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


 ********** Exceções ********


*/
class FileException {};
class InexFileException : FileException {};
class CorruptedFileException : FileException {};
/*
 * Classes contendo seus métodos de set(Definir) e 
 *  get(Pegar).
 *  Algumas classes possuem métodos de acesso a outras classes
 *  
 * Client */
Cliente::Cliente(int q)
{
    quant = new int[q];
}
Cliente::~Cliente()
{
    delete[] quant;
}
void Cliente::setBasicInfo(char *n, char *p, char ec, char s, char *pr, char *dp, int *nasc, long cpf, long rg, long cnh)
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
 
  
 
 **********  PROTÓTIPOS **********
  
  
  
*/
void setClientQuant() throw (Cliente::IndexException);         // Define os parâmetros de inicialização dos objetos de cliente
// Adiciona novos clientes
void setNewClient(int) throw (Cliente::IndexException, Cliente::EmptyInfoException, Cliente::EmptyAddressException, Cliente::EmptyContactException, Cliente::EmptyPurchaseException);                 
void setBrokerQuant() throw (Corretor::IndexException);        // Define os Parâmetros de inicialização dos objetos de Corretor
// Adiciona novos Corretores
void setNewBroker(int) throw (Corretor::EmptyInfoException, Corretor::EmptyContactException, Corretor::EmptyAddressException);                 
void setProductQuant() throw (Produto::IndexException);        // Define os parâmetros de inicialização dos objetos de Produto
// Adiciona novos Produtos
void setNewProduct(int) throw (Produto::EmptyInfoException, Produto::EmptyValueException);               
void OrdinFIle(char*);                  // Ordena as classes no arquivo
void SeCinF(char*);                     // Pesquisa as classes no arquivo
void SeSinF(char*);                     // Pesquisa as Strings dentro dos dados das classes
void SaCtoFile(char*, Cliente x) throw (FileException);       // Salva o Cliente no Arquivo 
void SaBtoFile(char*, Corretor x) throw (FileException);      // Salva o corretor no arquivo
void SaPtoFile(char*, Produto x) throw (FileException);       // Salva o produto no arquivo
void saReltoFile(char*, Relatorio x) throw (FileException);   // Salva o relatório no arquivo

/*


 **********  PRINCIPAL  **********


*/
int main(void) 
{ 
    return 0;
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
