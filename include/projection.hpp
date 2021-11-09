#pragma once
#include "fpr.hpp"

class P : public FPR {
 private:
  int index;
 public:
  void exec(std::vector<int> n) {
    result = {n[index - 1]};
  }

  P operator ()(int pos, std::vector<int> arg) {  // probar al final llamar a exec con pos directamente y quitar index
    index = pos;
    exec(arg);
    return *this;
  }
};