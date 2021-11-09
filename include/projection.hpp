#pragma once
#include "fpr.hpp"

class P : public FPR {
 private:
  long int   index;
 public:
  void exec(std::vector<long int  > n) {
    result = {n[index - 1]};
  }

  P operator ()(long int   pos, std::vector<long int  > arg) {  // probar al final llamar a exec con pos directamente y quitar index
    index = pos;
    exec(arg);
    return *this;
  }
};