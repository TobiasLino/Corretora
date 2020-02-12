// Copyright 2020 Tobias
#ifndef SRC_LIB_PESSOA_HPP_
#define SRC_LIB_PESSOA_HPP_

#include <string>

#include <mes.hpp>
#include <data.hpp>

class Pessoa {
 public:
  Pessoa();
  virtual ~Pessoa();
  virtual void set_nome(std::string nome) = 0;
  virtual void set_cpfCnpj(std::string cpfCnpj) = 0;
  virtual void set_gender(std::string sexo) = 0;
  virtual void set_person_type(std::string pessoa) = 0;
  virtual void set_nascimento(int dia, Mes mes, int ano) = 0;
 protected:
  std::string name_;
  std::string gender_;
  std::string cpfCnpj_;
  std::string peopleType_;
  Data *nascimento;
};

#endif  // SRC_LIB_PESSOA_HPP_
