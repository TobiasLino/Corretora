// Copyright 2020 Tobias
#ifndef SRC_LIB_CONTACT_CONTACT_HPP_
#define SRC_LIB_CONTACT_CONTACT_HPP_

#include <string>

class Contact {
 public:
  Contact() = default;
  Contact(std::string telefone, std::string email);
  virtual ~Contact();
  void set_phone(std::string tel);
  void set_email(std::string email);
  inline std::string get_phone();
  inline std::string get_email();
 private:
  std::string phone_;
  std::string email_;
};

#endif  // SRC_LIB_CONTACT_CONTACT_HPP_
