// Copyright 2020 Tobias
#ifndef SOLUCAO_LIB_CONTACT_CONTACT_HPP_
#define SOLUCAO_LIB_CONTACT_CONTACT_HPP_

#include <string>

class Contact {
 public:
  Contact();
  virtual ~Contact();
  void set_phone(std::string tel);
  void set_email(std::string email);
  std::string get_phone() __attribute__((pure));
  std::string get_email() __attribute__((pure));
 private:
  std::string phone_;
  std::string email_;
};

#endif  // SOLUCAO_LIB_CONTACT_CONTACT_HPP_
