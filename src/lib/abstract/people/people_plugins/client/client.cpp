// Copyright 2020 Tobias
#include <iostream>

#include "client.hpp"

Cliente::Cliente(std::string nome, std::string sexo,
          std::string cpfCnpj, std::string pessoa) {
  this->name_ = nome;
  this->gender_ = sexo;
  this->cpfCnpj_ = cpfCnpj;
  this->peopleType_ = pessoa;
}
Cliente::Cliente(std::string nome, std::string sexo) {
  this->name_ = nome;
  this->gender_ = sexo;
}
Cliente::~Cliente() {
  delete[] contato_;
  delete[] endereco_;
  delete[] historico_;
  delete[] arquivoAnexo;
}
void Cliente::set_contact(std::string telefone, std::string email) {
  contato_ = new Contact(telefone, email);
}
void set_address(std::string rua, std::string bairro,
                   std::string numero, std::string complemento = "",
                   std::string cidade, std::string cep) {
  endereco_ = new Address(rua, bairro, numero, complemento, cidade, cep);
}

