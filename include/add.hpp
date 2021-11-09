#pragma once
#include "fpr.hpp"
#include "successor.hpp"
#include "projection.hpp"

class ADD : public FPR {
  public:
  std::vector<long int> base(std::vector<long int> n) {
    P p;
    return p(1,n); 
  }

  std::vector<long int> recurrence(std::vector<long int> n) {
    S s;
    P p;
    return s * p(3, n);
  }
};