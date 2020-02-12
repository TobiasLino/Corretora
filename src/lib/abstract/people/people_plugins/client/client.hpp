#ifndef SRC_LIB_ABSTRACT_PEOPLE_PEOLE_PLUGINS_CLIENT_CLIENT_HPP
#define SRC_LIB_ABSTRACT_PEOPLE_PEOLE_PLUGINS_CLIENT_CLIENT_HPP

#include <string>

#include "../../../../contact/contact.hpp"
#include "../../../../address/address.hpp"
#include "../../../../historic/historic.hpp"
#include "../../../file/file_plugins/attachment/attachment.hpp"

class Cliente : public Pessoa {
 public:
  Cliente(std::string nome, std::string sexo,
          std::string cpfCnpj, std::string pessoa);
  Cliente(std::string nome, std::string sexo);
  Cliente() = default;
  virtual ~Cliente();
  void set_contact(std::string telefone, std::string email);
  void set_address(std::string rua, std::string bairro,
                   std::string numero, std::string complemento = "",
                   std::string cidade, std::string cep);
  // TODO  void set_historic();
  void set_attachment(std::string filename);
  //  Necessita implementação
  std::string get_name();
  std::string get_gender();
  std::string get_cpfCnpj();
  std::string get_peopleType();
  void get_address();
  void get_purchase();
  void get_contact();
  void get_attachment();
 private:
  std::string estadoCivil_;
  std::string profissao_;
  std::string documentoProfissao_;
  std::string rg_;
  Contact *contato_;
  Address *endereco_;
  Historic *historico_;
  double renda_;
  Anexo *arquivoAnexo_;
};

#endif  // SRC_LIB_ABSTRACT_PEOPLE_PEOLE_PLUGINS_CLIENT_CLIENT_HPP