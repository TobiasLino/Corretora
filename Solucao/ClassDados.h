#include <iostream>
#include <string>
using namespace std;
/*
 * CORRETORA DE SEGUROS
 * 
 * Aqui se encontra a solução para um sistema de corretora de seguros, onde é necessário realizar o cadastro
 *  dos clientes, dos produtos e dos corretores. Também é necessário gerar relatórios, realizar pesquisas com filtros,
 *  gerenciar operações com calendário(verificar os pagamentos do dia selecionado etc.) e realizar operações de telemarketing(envio de emails programado).
 * 
 * !!!!!!!!!!!!!1É necessário salvar os dados inseridos em um arquivo.!!!!!!!!!!!!!!
*/
/*
 * Classe de Dados do Cliente
 */
class Cliente {
    public:
        Cliente(int);
        ~Cliente();
        void setBasicInfo(string, string, string, string, string, string, int*, long, long, long);
        void setContact(string, string);
        void setAddress(string, string, string, string, int, long);
        void setPurchase(string, string, string, string, string, string, string, int);
        void setFile(string);
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
        int & operator[](int* n) {
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
        string nome[50];
        string pessoa[2];
        string EstadoCivil;   // C(asado), S(olteiro), D(ivorciado), V(iuvo)
        string sexo;          // M ou F
        string profissao[80];
        string DocProf[30];
        int nascimento[3];
        long CPF_CNPJ;
        long RG;
        long CNH;
        // Contato
        string telefone[16];
        string email[80];
        // Endereço
        string Rua[50];
        string Bairro[30];
        string Complemento[20];
        string Cidade[30];
        int numero;
        long CEP;
        // Demais dados
        string AssociacaoAMMG[20];
        string Corretor[50];
        string Historico[80];
        string Observacoes[80][10];
        string IndicacaoX[50];
        string IndicouXYZ[50][3];
        string RelacaoFamiliar[10][3];
        int Renda;
        // Anexo
        string Anexo[20];
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