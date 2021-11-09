#pragma once
#include "fpr.hpp"
#include "constant.hpp"
#include "projection.hpp"
#include "add.hpp"

class MULT : public FPR {
  public:
  std::vector<int> base(std::vector<int> n) {
    Z z;
    return z(n); 
  }

  std::vector<int> recurrence(std::vector<int> n) {
    ADD add;
    P p;
    return add({p(1, n), p(2, n)});
  }
};