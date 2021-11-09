#pragma once
#include "fpr.hpp"

class S : public FPR { 
  public:
  void exec(std::vector<long int  > n) {
    result.resize(0);
    result.push_back(arg[0] + 1);
  }
};