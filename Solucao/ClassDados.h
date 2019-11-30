#include <iostream>
#include <string>
/**
 * @brief Tipo enumerado para salvar o mês
*/
enum Mes { Janeiro=1,Fevereiro,Marco,Abril,Maio,junho,Julho,Agosto,Setembro,Outubro,Novembro,Dezembro };
using namespace std;
/** @brief CORRETORA DE SEGUROS */
namespace CORRETORA {
    /**
     * @details
     *  Aqui se encontra a solução para um sistema de corretora de seguros, onde é necessário realizar o cadastro
     *  dos clientes, dos produtos e dos corretores. Também é necessário gerar relatórios, realizar pesquisas com filtros,
     *  gerenciar operações com calendário(verificar os pagamentos do dia selecionado etc.) e realizar operações de telemarketing(envio de emails programado).
     * 
     * @todo É necessário salvar os dados inseridos em um arquivo.
    */
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
        */
        class ENDERECO {
            /** @details
             * 
             */
        public:
            ENDERECO(string r, string b, string com, string cid, int n, long c);
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
    /*
    * Classe de Pedido
    */
    class PEDIDO {
    public:
        PEDIDO(CLIENTE, CORRETOR, PRODUTO);
        void setPrestation();
        int getPrestation(){return prestations;}
    private:
        CLIENTE cliente;
        CORRETOR corretor;
        PRODUTO produto;
        CALENDARIO calendario;
        int prestations;
    };
    /** @brief Classes de cadastro de Cliente, Corretor e Produto. */
    namespace CADASTROS{
        using namespace CORRETORA::COMUNS;
        /**
         * @brief Classe de Dados do Cliente
        */
        class CLIENTE : public COMUNS::PESSOA{
            /**
             * @details
             */
            public:
                CLIENTE(string, string, string, string, string, string, int*, long, long, long);
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
}