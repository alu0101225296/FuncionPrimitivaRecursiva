#pragma once
#include "fpr.hpp"
#include "successor.hpp"
#include "projection.hpp"

class ADD : public FPR {
  public:
  std::vector<int> base(std::vector<int> n) {
    P p;
    return p(1,n); 
  }

  std::vector<int> recurrence(std::vector<int> n) {
    S s;
    P p;
    return s * p(1, n);
  }
};