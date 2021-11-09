#pragma once
#include "fpr.hpp"
#include "constant.hpp"
#include "projection.hpp"
#include "add.hpp"

class MULT : public FPR {
  public:
  std::vector<long int> base(std::vector<long int> n) {
    Z z;
    return z(n); 
  }

  std::vector<long int> recurrence(std::vector<long int> n) {
    ADD add;
    P p;
    return add({p(3, n), p(1, n)});
  }
};