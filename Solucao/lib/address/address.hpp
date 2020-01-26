// Copyright 2020 Tobias
#ifndef SOLUCAO_LIB_ADDRESS_ADDRESS_HPP_
#define SOLUCAO_LIB_ADDRESS_ADDRESS_HPP_

#include <string>

class Address {
 public:
  Address();
  virtual ~Address();
  void set_street(std::string rua);
  void set_neighborhood(std::string bairro);
  void set_number(std::string numero);
  void set_complement(std::string complemento);
  void set_city(std::string cidade);
  void set_zip(std::string cep);
  std::string get_street() __attribute__((pure));
  std::string get_neighborhood() __attribute__((pure));
  std::string get_number() __attribute__((pure));
  std::string get_complement() __attribute__((pure));
  std::string get_city() __attribute__((pure));
  std::string get_zip() __attribute__((pure));
 private:
  std:string street_;
  std:string neighborhood_;
  std:string number_;
  std:string city_;
  std:string complement_;
  std:string zip_;
};

#endif  // SOLUCAO_LIB_ADDRESS_ADDRESS_HPP_
