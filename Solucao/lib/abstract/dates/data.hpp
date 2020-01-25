// Copyright 2020 Tobias
#ifndef SOLUCAO_LIB_ABSTRACT_DATES_DATA_HPP_
#define SOLUCAO_LIB_ABSTRACT_DATES_DATA_HPP_

#include <iostream>

#include <mes.hpp>
// Classe Abstrata para registro de data.
// Necessário implementação pelo fato de ser uma biblioteca dinâmica.
class Data {
 public:
  Data();
  virtual ~Data();
  virtual void set_day(int dia) = 0;
  virtual void set_mes(Mes mes) = 0;
  virtual void set_ano(int ano) = 0;
  virtual int get_day() = 0;
  virtual int get_mes() = 0;
  virtual int get_ano() = 0;
  friend std::ostream& operator<<(std::ostream& out, Data&data);
 protected:
  int dia_;
  Mes mes_;
  int ano_;
};


extern "C" {
  typedef Data *D_load_t();
  typedef void D_unload_t(Data *);
}

#endif  // SOLUCAO_LIB_ABSTRACT_DATES_DATA_HPP_
