#pragma once
#include "fpr.hpp"
#include "successor.hpp"
#include "constant.hpp"
#include "projection.hpp"
#include "mult.hpp"

class POW : public FPR { 
  public:
  std::vector<long int> base(std::vector<long int> n) {
    Z z;
    S s;
    return s * z(n); 
  }

  std::vector<long int> recurrence(std::vector<long int> n) {
    MULT mult;
    P p;
    return mult({p(1, n), p(2, n)});
  }
};