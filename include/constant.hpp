#pragma once
#include "fpr.hpp"

class Z : public FPR {
  void exec(std::vector<long int  > n) {
    result.resize(0); 
    result.push_back(0);
  }
};