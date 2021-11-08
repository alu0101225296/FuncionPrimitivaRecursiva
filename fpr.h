#include <vector>
#include <iostream>

class FPR {
 protected:
 public:
  FPR();
  ~FPR();
};

// FPR operator

class Z : public FPR {
  Z();
};

class S : public FPR {
  S();
};

class P : public FPR {
  P();
};


  float Combinacion(float, float);