#pragma once
#include "fpr.hpp"

class S : public FPR { 
  public:
  void exec(std::vector<int> n) {
    result.resize(0);  // no me fio
    result.push_back(arg[0] + 1);
  }
};