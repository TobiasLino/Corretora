// Copyright 2020 Tobias
// Plugin de data.hpp
#ifndef SOLUCAO_LIB_NASCIMENTO_NASCIMENTO_HPP_
#define SOLUCAO_LIB_NASCIMENTO_NASCIMENTO_HPP_

#include <iostream>

#include <../dates/data.hpp>

class Nascimento : public Data {
 public:
  Nascimento();
  ~Nascimento();
  void set_day(int dia);
  void set_mes(Mes mes);
  void set_ano(int ano);
  int get_day();
  int get_mes();
  int get_ano();
  friend std::ostream& operator<<(std::ostream& out, Nascimento& data);
};

extern "C" {
  Data *load_plugin(void) {
    return new Nascimento;
  }
  void unload_plugin(Data *d) {
    delete d;
  }
}

#endif  // SOLUCAO_LIB_NASCIMENTO_NASCIMENTO_HPP_
