// Copyright 2020 Tobias
#include <string>

#include <contact.hpp>

Contact::Contact() {
  this->phone_ = "";
  this->email_ = "";
}
Contact::~Contact() {
  std::cout << "DESTRUCTION: CONTACT" << std::endl;
}
void set_phone(std::string tel) {
  this->phone_ = tel;
}
void set_email(std::string email) {
  this->email_ = email;
}
std::string get_phone() __attribute__((pure)) {
  return this->phone_;
}
std::string get_email() __attribute__((pure)) {
  return this->email_;
}
