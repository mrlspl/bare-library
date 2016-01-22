#pragma once

#include <string>

namespace BareLibrary
{
  class HelloWorld
  {
  public:
    std::string sayHello();

    void setNumber(int const number) { number_ = number; }
    int getNumber() { return number_; }

  private:
    int number_;
  };
}
