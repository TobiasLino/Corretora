// Copyright 2020 Tobias
#ifndef SRC_LIB_ADDRESS_ADDRESS_HPP_
#define SRC_LIB_ADDRESS_ADDRESS_HPP_

#include <string>

class Address {
 public:
  Address() = default;
  Address(std::string rua, std::string bairro,
          std::string numero, std::string complemento = "",
          std::string cidade, std::string cep);
  virtual ~Address();
  void set_street(std::string rua);
  void set_neighborhood(std::string bairro);
  void set_number(std::string numero);
  void set_complement(std::string complemento);
  void set_city(std::string cidade);
  void set_zip(std::string cep);
  inline std::string get_street();
  inline std::string get_neighborhood();
  inline std::string get_number();
  inline std::string get_complement();
  inline std::string get_city();
  inline std::string get_zip();
  std:string street_;
  std:string neighborhood_;
  std:string number_;
  std:string city_;
  std:string complement_;
  std:string zip_;
};

#endif  // SRC_LIB_ADDRESS_ADDRESS_HPP_
