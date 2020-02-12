// Copyright 2020 Tobias
#include <iostream>
#include <string>

#include <address.hpp>

Address::Address() {
  this->street_ = "";
  this->neighborhood_ = "";
  this->number_ = "";
  this->city_ = "";
  this->complement_ = "";
  this->zip_ = "";
}
Address::Address(std::string rua, std::string bairro,
                 std::string numero, std::string complemento = "",
                 std::string cidade, std::string cep) {
  this->street_ = rua;
  this->neighborhood_ = bairro;
  this->number_ = numero;
  this->city_ = cidade;
  this->complement_ = complemento;
  this->zip_ = cep;
}
Address::~Address() {
  std::cout << "DESTRUCTION: ADDRESS" << std::endl;
}
void set_street(std::string rua) {
  this->street_ = rua;
}
void set_neighborhood(std::string bairro) {
  this->neighborhood_ = bairro;
}
void set_number(std::string numero) {
  this->number_ = numero;
}
void set_complement(std::string complemento) {
  this->complement_ = complemento;
}
void set_city(std::string cidade) {
  this->city_ = cidade;
}
void set_zip(std::string cep) {
  this->zip_ = cep;
}
std::string get_street() __attribute__((pure)) {
  return this->street_;
}
std::string get_neighborhood() __attribute__((pure)) {
  return this->neighborhood_;
}
std::string get_number() __attribute__((pure)) {
  return this->number_;
}
std::string get_complement() __attribute__((pure)) {
  return this->complement_;
}
std::string get_city() __attribute__((pure)) {
  return this->city_;
}
std::string get_zip() __attribute__((pure)) {
  return this->zip_;
}
