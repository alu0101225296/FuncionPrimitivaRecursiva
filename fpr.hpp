#include <vector>
#include <iostream>

class FPR {
 protected:
  std::vector<int> val;
 public:
  FPR() {
    
  }
  ~FPR() {

  }
  void setV(std::vector<int> n) {
    val = n;
  }

  std::vector<int> Val() {
    return val;
  }

  virtual void exec() { 
    std::cout << "xd";
  }

  FPR operator ()(std::vector<int> arg) {
    FPR result = *this;
    result.setV(arg);
    result.exec();
    return result;
  }    
};

class Z : public FPR {
 public:
  using FPR::FPR;
  void exec() {
    val.resize(1);
    val[0] = 0;
  }
};

class S : public FPR {
  public:
  using FPR::FPR;
  void exec() {
    val.resize(1);
    val[0] = val[0]++;
  }
};

class P : public FPR {
  public:
  int index;
  std::vector<int> val;
  void setPos(int pos) {
    index = pos;
  }
  void exec() {
    std::vector<int> dummy = val;
    val.resize(0);
    val.push_back(dummy[index - 1]);
  }

  P operator ()(int pos, std::vector<int> arg) {
    P result = *this;
    result.setPos(pos);
    result.setV(arg);
    result.exec();
    return result;
  }
};

FPR operator %(FPR& op1, FPR& op2) {
  return op1(op2.Val());
}


class SUMA : public FPR {
  public:
  using FPR::FPR;
  void exec() {
    if(val.size() != 2) std::cout << "Error suma";
    else {
      P Proyeccion;
      if(val[2] == 0) {
        val = Proyeccion(1,val).Val();
      }
    }
  }
};