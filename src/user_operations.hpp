#ifndef USER_OPERATIONS_HPP
#define USER_OPERATIONS_HPP

#include <iostream>
#include <string>
#include "data.hpp"

namespace user_operations {
class RELATORIO {
 public:
  RELATORIO(int);
  void setResume();
  void getResume();
  void setProductionRel(int, std::string, std::string, double, double, double, double, double, double);
  void setPRtoAMMg();
  void getRel();
 private:
  int periodo[3];
  std::string ClientInic;
  std::string Ramo;
  double ValorParcela;
  double comissao;
  double AMMGpercent;
  double ValorsemDeduc;
  double Deduc;
  double Repasse;
};
class FILTRO {
 public:
  FILTRO(int);
  void setFilters(std::string, std::string,std::string, int, long);
 private:
  // Filtros
  std::string PNome;
  std::string Pemail;
  std::string Pseguro;
  int Pidade;
  long PCPF;
};

class Prestacao : public Data {
 public:
  Prestacao(const Cadastro::Produto& produto);
  void set_begin(int,Mes, int);
  void set_end(int, Mes, int);
  void get_allPrestations();
  void get_begin();
  void get_end();
 private:
  Data DataInicio, DataFinal; // Data inicio e final
  int prestation;     // total de prestações 
};

class CALENDARIO {
 public:
  void AdicionarPagamento(int, double);
  void ImprimirPagamentos(int[]);
 private:
  int Acess;  // Define o tipo de acesso 0 ou 1
};
class TELEMARKETING {
 public:
  void Autosend();
  void SendEmail();
  void SelectClient();
 private:
  std::string Sender;
  std::string Recipient;
  std::string Conteudo;      // File
};
class HISTORICO {
 public:
  HISTORICO();
 private:
  Data Data;
};

}

#endif