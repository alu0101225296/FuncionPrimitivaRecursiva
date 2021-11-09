#pragma once
#include "fpr.hpp"
#include "successor.hpp"
#include "constant.hpp"
#include "projection.hpp"
#include "mult.hpp"

class POW : public FPR { 
  public:
  std::vector<int> base(std::vector<int> n) {
    Z z;
    S s;
    return s * z(n); 
  }

  std::vector<int> recurrence(std::vector<int> n) {
    MULT mult;
    P p;
    return mult({p(1, n), p(2, n)});
  }
};