#ifndef DADOS_HPP
#define DADOS_HPP

// CorretorA DE SEGUROS
#include <iostream>
#include <memory>
#include <string>
#include "global_data.hpp"
#include "user_operations.hpp"

namespace Cadastro{

class Pedido {
public:
  Pedido(const Cadastro::Cliente& cliente,
                  const Cadastro::Corretor& corretor,
                  const Cadastro::Produto& produto);
  void set_Purchase(std::string, std::string, std::string,
                   std::string, std::string, std::string, std::string);
  void set_Prestation(user_operations::PRESTACAO);
  int get_Prestation(){return prestations;}
 private:
    Cadastro::Cliente cliente_;
    Cadastro::Corretor corretor_;
    Cadastro::Produto produto_;
    std::unique_ptr<CALENDARIO> calendario;
    user_operations::PRESTACAO prestacoes;
    int prestations;
    std::string AssociacaoAMMG;
    std::string Observacoes;
    std::string IndicacaoX;
    std::string IndicouXYZ;
    std::string RelacaoFamiliar;
};
Pedido::Pedido(CLIENTE cl, Corretor co, Produto po)
{
    this.cliente = cl;
    this.Corretor = co;
    this.Produto = po;
}
void Pedido::set_Purchase(string a = "", string obs = "", string indx = "", string indxyz = "", string rf = "")    // cria a instância com valores default
{
    AssociacaoAMMG = a;
    Observacoes = obs;
    IndicacaoX = indx;
    IndicouXYZ = indxyz;
    RelacaoFamiliar = rf;
}
//
// CLIENTE
//
class Cliente : public Pessoa{
 public:
  Cliente(std::string nome, std::string, std::string,
          std::string, std::string, std::string, int*,
          long, long, long, double);
  void set__contact(std::string, std::string);
  void set__address(std::string rua = "", std::string bairro = "",
                  std::string complemento = "",
                  std::string cidade = "", int numero = 0,
                  long cep = 0);
  void set_history(user_operations::HISTORICO);
  void set_file(std::string);
  void get_Name();
  void get_Contact();
  void get_Addres();
  void get_Purchase();
  void get__file();
  void WriteToFIle();
 private:
  std::string estado_civil_;   // C(asado), S(olteiro), D(ivorciado), V(iuvo)
  std::string profissao_;
  std::string documento_profissao_;
  long cpf_cnpj_;
  long rg_;
  long cnh_;
  Contact *contato_;
  Address *endereco_;
  user_operations::HISTORICO historico_;
  double renda_;
  File *anexo_;
};
// MÉTODOS
Cadastro::Cliente::Cliente(std::string nome = "", std::string pessoa = "",
                           std::string estado_civil = "", std::string sexo = "",
                           std::string profissao = "", std::string documento_profissao = "",
                           long cpf = 0, long rg = 0, long cnh = 0,
                           double renda = 0)   /// cria a instância com valores default
{
  this->nome_ = nome;
  this->pessoa_ = pessoa;
  this->estado_civil_ = estado_civil;
  this->sexo_ = sexo;
  this->profissao_ = profissao;
  this->documento_profissao_ = documento_profissao;
  this->cpf_cnpj_ = cpf;
  this->rg_ = rg;
  this->cnh_ = cnh;
  this->renda_ = renda;
}
void Cliente::set_contact(std::string telefone = "", std::string email = "") {
  contato_->set_phone(telefone);
  contato_->set_email(email);
}
void Cliente::set_Address(std::string rua = "", std::string bairro = "", std::string complemento = "",
                         std::string cidade = "", int numero = 0, long cep = 0) {
  endereco_->set__address(rua, bairro, complemento, cidade, numero, cep);
}

void Cliente::set_File(std::string file_name) {
  anexo_->OpenFile(file_name);
}
void Cliente::get_Name() const {
  std::cout  << "Nome: " << this->nome_ << std::endl
        << "Pessoa(Física ou Jurídica): " << this->pessoa_ << std::endl
        << "Estado Civil(C(asado), "
        << "S(olteiro), D(ivorciado), "
        << "V(iuvo)): " << this->estadocivil_ << std::endl
        << "Sexo: " << this->sexo_ << std::endl
        << "Data de Nascimento" << this->nascimento_ << std::endl
        << "Profissão: " << this->profissao_ << std::endl
        << "Documento Profissional: " << this->documento_profissao_ << std::endl
        << "CPF ou CNPJ: " << this->cpf_cnpj_ << std::endl
        << "RG: " << this->rg_ << std::endl
        << "CNH: " << this->cnh_ << std::endl;
}
void Cliente::get_Contact() const {
  std::cout  << "Telefone: " << this->telefone_ << std::endl
        << "Email: " << this->email_ << std::endl;
}
void Cliente::get_Addres() const {
  endereco_->get__address();
}
void Cliente::get_Purchase() const {
  std::cout << "Associação com a Corretora: " << this->associacao_ << std::endl
  << "Corretor: " << this->corretor_ << std::endl
  << "Histórico: " << this->historico_ << std::endl
  << "Renda" << this->renda_ << std::endl
  << "Observações" << this->observacoes_ << std::endl
  << "Indicação de: " << this->indicacao_x_ << std::endl
  << "Indicou: " << this->indicou_x_y_z_ << std::endl
  << "Relação Familiar com o indicado: " << this->relacao_familiar_ << std::endl;
}
void Cliente::get_File() const {}
void Cliente::get_FullClient() const {
    get_Name();
    get_Contact();
    get_Address();
    get_File();
    get_Purchase();
}

//
// CORRETOR
//
class Corretor : public Pessoa {
 public:
  Corretor();
  void set_broker(std::string, int, long);
  void set_contact(std::string, std::string);
  void set_adress(std::string rua = "", std::string bairro = "",
                 std::string complemento = "",
                 std::string cidade = "", int numero = 0,
                 long cep = 0);
  void get_name();
  void get_adress();
  void get_broker();
 private:
  // Informações Básicas
  std::string nome_;
  int type_;
  long cpf_cnpj_;
  Contact *contato_;
  Address *endereco_;
};
Corretor::Corretor(std::string nome="", int tipo_=0, long cpf=0)
{
  this->nome_ = n;
  this->type_ = t;
  this->cpf_cpnj_ = cpf;
}
void Corretor::set_contact(std:string telefone = "", std:string email = "")
{
  contato_->set_phone(telefone);
  contato_->set_email(email);
}
void Corretor::set_adress(std::string rua = "", std::string bairro = "",
                         std::string complemento = "",
                         std::string cidade = "", int numero = 0, long cep = 0) {
  endereco_->set__address(rua, bairro, complemento, cidade, numero, cep);
}
void Corretor::get_name() {
  std::cout << "Nome: " << this->nome_ << std::endl
  << "Tipo de Usuário: " << this->type_ << std::endl
  << "(1 - acesso completo, 2 - acesso apenas "
  << "à visualização dos segurados vinculados, e "
  << "3 - visualização completa)" << std::endl
  << "CPF/CNPJ: " << this->cpf_cnpj_ << std::endl
  << "Telefone: " << this->telefone_ << std::endl
  << "Email: " << this->email_ << std::endl;
}
void Corretor::get_address() {
  endereco_->get_address();
}
void Corretor::getBroker() {
  getName();
  getAddress();
}

/*
* Classe de Dados de Produto
*/
class Produto {
 public:
  Produto(int);
  int set_ID(int);
  void set_Product(std::string, std::string, std::string,
                  std::string, std::string, std::string,
                  double, int);
  void set_Values(double, double, double, std::string,
                  std::string, std::string);
  void set_File(std::string);
  void get_Product();
  int get_Prestation(){};
 private:
  int id_;
  // Informações Básicas
  std::string seguradora_;
  std::string ramo_;
  std::string nome_;
  std::string corretor_;
  std::string vigencia_;
  std::string agenciamento_;
  double comissao_;
  int tipo_;
  // Valores
  double premio_;
  double comissionamento_;
  double capitalsegurado_;
  std::string veiculo_;
  std::string id_;
  std::string observacoes_;
  // Anexo
  std::string anexo_;
};
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
void Produto::getProduct() const {
  std::cout << "Seguradora: " << this->seguradora_ << std::endl
  << "Ramo: " << this->ramo_ << std::endl
  << "Nome: " << this->nome_ << std::endl
  << "Corretor: " << this->corretor_ << std::endl
  << "VIgencia: " << this->vigencia_ << std::endl
  << "Agenciamento: " << this->agenciamento_ << std::endl
  << "Comissão: " << this->comissao_ << std::endl
  << "Tipo: " << this->tipo_ << std::endl
  << "(seguro novo, renovação, endosso; "
  << "mudança de endereço e capital segurado, etc)" << std::endl
  << "Prêmio: " << this->premio_ << std::endl
  << "Comissionamento: " << this->comissionamento_ << std::endl
  << "Veiculo: " << this->veiculo_ << std::endl
  << "ID: " << this->id_ << std::endl
  << "Observações: " << this->observacoes_ << std::endl;
}

}

#endif
