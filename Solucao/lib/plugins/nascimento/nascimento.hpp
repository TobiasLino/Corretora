// Copyright 2020 Tobias
#ifndef SOLUCAO_LIB_NASCIMENTO_NASCIMENTO_HPP_
#define SOLUCAO_LIB_NASCIMENTO_NASCIMENTO_HPP_

#include <iostream>
// Incluindo a biblioteca data
#include <../dates/data.hpp>

// Define a data de nascimento dos clientes e corretores. Necessita que
// o usuário defina os valores na chamada.
//
// Exemplo:
//  Cliente c, *ptr;
//  ptr = &c;
//  ptr->set_nascimento(24, OUTUBRO, 2001);
//
//  ** Aqui a chamada invoca uma operação da classe cliente que chama as
//  ** funções set_ correspondentes ao dia, mes e ano.
//  **
//  **  set_nascimento(int dia, Mes mes, int ano) {
//  **    nasc_->set_day(dia);
//  **    nasc_->set_mes(mes);
//  **    nasc_->set_ano(ano);
//  **  }
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

// Necessário para que o sistema chame o plugin nascimento pertencente a
// bilbioteca data.
extern "C" {
  Data *load_plugin(void) {
    return new Nascimento;
  }
  void unload_plugin(Data *d) {
    delete d;
  }
}

#endif  // SOLUCAO_LIB_NASCIMENTO_NASCIMENTO_HPP_
