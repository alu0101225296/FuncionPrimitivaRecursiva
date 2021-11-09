#pragma once
#include "fpr.hpp"

class Z : public FPR {
  void exec(std::vector<int> n) {
    result.resize(0); // no me fio
    result.push_back(0);
  }
};