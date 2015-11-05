#pragma once

#include <mex.h>
#include <vector>
#include <stdexcept>

template <typename T>
class MatlabInterface
{
public:
  static unsigned registerInstance(T& instance)
  {
    std::vector<T> &objects = getInstances_();
    unsigned index = objects.size();
    objects.push_back(instance);
  }

  static T &getInstance(unsigned i)
  {
    try
    {
      return getInstances_().at(i);
    }
    catch(std::out_of_range&)
    {
      throw(std::out_of_range("No object with the given handle is registered."));
    }
  }


private:
  MatlabInterface();
  MatlabInterface(MatlabInterface const&);

  static std::vector<T> &getInstances_()
  {
      static std::vector<T> objects_;
      return objects_;
  }
};
