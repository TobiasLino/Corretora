/** @brief CORRETORA DE SEGUROS */
#include <iostream>
#include <string>
/**
 * @brief Tipo enumerado para salvar o mês
*/
enum Mes { Janeiro=1,Fevereiro,Marco,Abril,Maio,junho,Julho,Agosto,Setembro,Outubro,Novembro,Dezembro };
using namespace std;
/** @brief Classe que registra o pedido, mesclando cliente, produto e corretor. */
class PEDIDO {
    using namespace CADASTRO;
    /**
     * @details 
     *  Registra o pedido como mediador, anexando as informações do cliente,
     *  produto e corretor, bem como as prestações, no calendário.
     *  O usuário pode obter todas as informações e imprimi-las na tela.
     * @param PEDIDO        Construtor principal
     * @param CLIENTE       Instância de CLIENTE
     * @param CORRETOR      Instância de CORRETOR
     * @param PRODUTO       Instância de PRODUTO
     * @param CALENDARIO    Instância de CALENDARIO(cria as prestações)
     * @param prestations   Número de Prestações
     * @return              Registro do pedido
     */
public:
    PEDIDO(CADASTRO::CLIENTE, CADASTRO::CORRETOR, CADASTRO::PRODUTO);
    void setPrestation();
    int getPrestation(){return prestations;}
private:
    CADASTRO::CLIENTE cliente;
    CADASTRO::CORRETOR corretor;
    CADASTRO::PRODUTO produto;
    USEROPERATIONS::CALENDARIO calendario;
    int prestations;
};
/** @brief Classe File para arquivos anexados. */
class FILE {
    /**
     * @details
     *  Salva os arquivos anexados nos cadastros como classes.
     */
};
/** @brief Classes comuns ao corretor e Cliente. */
namespace COMUNS {
    /**
     *  @brief Classe Pessoa comum a Corretor e Cliente
     */
    class PESSOA{};
    /**
     * @brief Classe endereço, comum a cliente e corretor
     * @details 
     *  Define os dados para endereço e os atribui a suas variáveis correspondentes.
    */
    class ENDERECO {
    public:
        /** 
         * @brief Construtor ENDEREÇO
         * @details 
         *  Constrói uma instância da classe. Se estiver vazia, cria com parâmetros default.
         * @param r     Rua a ser inserida
         * @param b     Bairro a ser inserido
         * @param com   Complemento, se houver
         * @param cid   Cidade a ser inserida
         * @param n     Numero da casa
         * @param c     CEP da Rua
         * @return      Constroi uma instancia da classe ENDERECO com os parametros passados
        */
        ENDERECO(string, string, string, string, int, long);
        /**
         * @brief Método get do endereço.
         * @return Imprime o endereço no terminal.
         */
        void getAddress();
    private:
        string Rua;
        string Bairro;
        string Complemento;
        string Cidade;
        int numero;
        long CEP;
    };
}
/** @brief Classes de cadastro de Cliente, Corretor e Produto. */
namespace CADASTRO{
    using namespace CORRETORA::COMUNS;
    /**
     * @brief Classe de Dados do Cliente
     * @details
     *  Registro dos dados do cliente, com métodos de acesso às informações privadas.
     *  Herda PESSOA.
    */
    class CLIENTE : public COMUNS::PESSOA{
        public:
            /**
             * @brief Construtor de Cliente
             * @details
             *  Cria a instância de Cliente.
             * @param string n     Nome do cliente
             * @param string p     Tipo de pessoa: Física ou Jurídica
             * @param string ec    Estado Civil
             * @param string s     Sexo
             * @param string pr    Profissão
             * @param string dp    Documento de Profissão
             * @param int[] nasc  Data de Nascimento
             * @param long cpf   CPF/CNPJ
             * @param long rg    RG
             * @param long cnh   CNH
             * @return      Cria a instância da classe cliente
             */
            CLIENTE(string, string, string, string, string, string, int*, long, long, long);
            /**
             * @brief Define o contato
             * @param t     Telefone
             * @param e     Email
             * @return      Atribui os valores às variáveis de contato
             */
            void setContact(string, string);
            /**
             * @brief Define o endereço do cliente
             * @details
             *  Atribui os valores a uma instância da classe ENDERECO.
             * @see COMUNS::ENDERECO
             */
            void setAddress(string, string, string, string, int, long);
            void setPurchase(string, string, string, string, string, string, string, int);
            void setFile(string);
            void getName();
            void getContact();
            void getAddres();
            void getPurchase();
            void getFIle();
            void getFullClient();
        private:
            // Informações Básicas
            string nome;
            string pessoa;
            string EstadoCivil;   // C(asado), S(olteiro), D(ivorciado), V(iuvo)
            string sexo;          // M ou F
            string profissao;
            string DocProf;
            int nascimento[3];
            long CPF_CNPJ;
            long RG;
            long CNH;
            // Contato
            string telefone;
            string email;
            // Endereço
            ENDERECO endereco;
            // Demais dados
            string AssociacaoAMMG;
            string Corretor;
            string Historico;
            string Observacoes;
            string IndicacaoX;
            string IndicouXYZ;
            string RelacaoFamiliar;
            int Renda;
            // Anexo
            string Anexo;
    };
    /*
    * Classe de Dados do Corretor
    */
    class CORRETOR : public COMUNS::PESSOA {
        public:
            CORRETOR();
            void setBroker(string, int, long);
            void setContact(string, string);
            void setAddres(string, string, string, string, int, long);
            void getName();
            void getAddress();
            void getBroker();
        private:
            // Informações Básicas
            string Nome;
            int type;
            long CPF_CNPJ;
            // Contato
            string email;
            string telefone;
            // Endereço
            ENDERECO endereco;
    };
    /*
    * Classe de Dados de Produto
    */
    class PRODUTO {
        public:
            PRODUTO(int);
            int setID(int);
            void setProduct(string, string, string, string, string, string, float, int);
            void setValues(float, float, float, string, string, string);
            void setFile(string);
            void getProduct();
            int getPrestation(){return prestacoes;};
        private:
            int ID;
            // Informações Básicas
            string Seguradora;
            string Ramo;
            string Nome;
            string Corretor;
            string Vigencia;
            string Agenciamento;
            float Comissao;
            int Tipo;
            // Valores
            float premio;
            float comissionamento;
            float capitalsegurado;
            string Veiculo;
            string id;
            string Observacoes;
            // Anexo
            string anexo;
    };  
}
/**
 * @brief Operações do usuário
 */
namespace USEROPERATIONS {
    /*
    * Classe de Dados de Relatório
    */
    class RELATORIO {
        public:
            RELATORIO(int);
            void setResume();
            void getResume();
            void setProductionRel(int, string, string, float, float, float, float, float, float);
            void setPRtoAMMg();
            void getRel();
        private:
            int *quant;
            // Basic
            int periodo[3];
            string ClientInic;
            string Ramo;
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
    class FILTRO {
        public:
            FILTRO(int);
            void setFilters(string,string,string, int, long);
        private:
            int *quant;
            // Filtros
            string PNome;
            string Pemail;
            string Pseguro;
            int Pidade;
            long PCPF;
    };
    /*
    *  Classe de identificação do mês
    */
    class DATA {
    public:
        DATA(int,Mes,int);
        int getDay(){return dia;}
        int getMonth(return mes;)
        int getYear(){return ano;}
        friend ostream& operator<<(ostream&, DATA &data);
    private:
        int dia;
        Mes mes;  
        int ano;
    };
    /*
    * Classes de Prestações
    */
    class PRESTACAO : public DATA {
    public:
        PRESTACAO(PRODUTO);
        void setBegin(int,Mes, int);
        void setEnd(int, Mes, int);
        void getAllPrestations();
        void getBegin();
        void getEnd();
    private:
        DATA dataInicio, dataFinal; // data inicio e final
        int prestation;     // total de prestações 
    };
    /* 
    * Classe de Acesso ao Calendário
    */
    class CALENDARIO {
        public:
            void AdicionarPagamento(int, float);
            void ImprimirPagamentos(int[]);
        private:
            int Acess;  // Define o tipo de acesso 0 ou 1
    };
    /* 
    * Classe de Operações de Telemarketing
    */
    class TELEMARKETING {
        public:
            void Autosend();
            void SendEmail();
            void SelectClient();
        private:
            string Sender;
            string Recipient;
            string Conteudo;      // File
    };
}