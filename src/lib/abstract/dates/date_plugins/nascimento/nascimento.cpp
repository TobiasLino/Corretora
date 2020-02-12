// Copyright 2020 Tobias
// plugin de data.hpp
#include <iostream>

#include <nascimento.hpp>

Nascimento::Nascimento() {
  this->dia_ = 0;
  this->mes_ = JANEIRO;
  this->ano_ = 0;
}
Nascimento::~Nascimento() {
  std::cout << "DESTRUCTION: NASCIMENTO." << std::endl;
}
void Nascimento::set_day(int dia) {
  this->dia_ = dia;
}
void Nascimento::set_mes(Mes mes) {
  this->mes_ = mes;
}
void Nascimento::set_ano(int ano) {
  this->ano_ = ano;
}
int Nascimento::get_day() {
  return this->dia_;
}
int Nascimento::get_mes() {
  return this->mes_;
}
int Nascimento::get_ano() {
  return this->ano_;
}
std::ostream& operator<<(std::ostream& out, Nascimento& data) {
  out << "Dia: " << data.dia_ << ", Mes: " << data.mes_
      << ", ano: " << data.ano_;
  return out;
}
