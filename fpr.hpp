#include <vector>
#include <iostream>

class FPR {
 protected:
  float val;
 public:
  FPR();
  explicit FPR(float n) {
    val = n;
  }
  ~FPR();
  float Val() {
    return val;
  }
  virtual void exec();
};

class Z : public FPR {
 public:
  using FPR::FPR;
  void exec() {
    val = 0;
  }
};

class S : public FPR {
  using FPR::FPR;
  void exec() {
    val = val++;
  }
};

class P : public FPR {
  int index;
  std::vector<float> val;
  P(std::vector<float> n, int i) {
    val = n;
    index = i;
  }
  void exec() {
    val = n[i - 1];
  }
};


FPR operator %(FPR& op1, FPR& op2) {
  return op1(op2.Val());
}