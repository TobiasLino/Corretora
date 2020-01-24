// Copyright 2020 Tobias
#ifndef SOLUCAO_LIB_PESSOA_HPP_
#define SOLUCAO_LIB_PESSOA_HPP_

#include <string>

#include <mes.hpp>
#include <data.hpp>

class Pessoa {
 public:
  Pessoa();
  virtual ~Pessoa();
  virtual void set_nome() = 0;
  virtual void set_cpf_cnpj() = 0;
  virtual void set_sex() = 0;
  virtual void set_person_type(std::string pessoa) = 0;
  virtual void set_nascimento(int dia, Mes mes, int ano) = 0;
 protected:
  std::string nome_;
  std::string sexo_;
  std::string cpf_cnpj_;
  Data *nascimento;
};

#endif  // SOLUCAO_LIB_PESSOA_HPP_
