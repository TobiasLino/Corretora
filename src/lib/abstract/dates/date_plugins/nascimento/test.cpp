#include <iostream>
#include <memory>

#include "nascimento.hpp"

int main(void) {
  std::unique_ptr<Nascimento> pborn(new Nascimento());
  pborn->set_day(24);
  pborn->set_mes(OUTUBRO);
  pborn->set_ano(2001);
  std::cout << *pborn << std::endl;
}
