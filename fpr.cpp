#include <vector>
#include <iostream>
#include <assert.h> 

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

  virtual void exec() { 
    std::cout << "xd";
  }

  FPR operator ()(std::vector<int> arg) {
    setV(arg);
    exec();
    return *this;
  }   

  FPR operator *(FPR op) {
    setV(op);
    exec();
    return *this;
    // return *this(op.Val());
  } 

  operator std::vector<int>() {
    return val;
  }

  operator int() {
    return val[0];
  }

  friend std::ostream& operator << (std::ostream& out, const FPR& fpr);
};

std::ostream& operator << (std::ostream& out, const FPR& fpr) {
  if(fpr.val.size() > 1)
    for(auto val : fpr.val)
      out << val << " ";
  else out << fpr.val[0];
  return out;
}


class Z : public FPR { // sirve
 public:
  using FPR::FPR;
  void exec() {
    val.resize(1);
    val[0] = 0;
  }
};

class S : public FPR {  // sirve
  public:
  using FPR::FPR;
  void exec() {
    val.resize(1);
    val[0] = val[0] + 1;
  }
};

class P : public FPR { // sirve
 private:
  int index;
 public:
  void setPos(int pos) {
    index = pos;
  }
  void exec() {
    val = {val[index - 1]};
  }

  P operator ()(int pos, std::vector<int> arg) {
    setPos(pos);
    setV(arg);
    exec();
    return *this;
  }
};


class SUMA : public FPR {
  public:
  using FPR::FPR;
  void exec() {
    assert(val.size() == 2);
    P p;
    if(val[1] == 0) 
      val = p(1,val);
    else {
      SUMA suma;
      S s;
      S s1;
      //suma({val[0], val[1]}).Val2();
      val = (s * p(2,val));
      // val = (s * p(3, {val[0], val[1], s1({val[0], val[1]}).Val2()})).Val();
    }
  }
};


int main() {
  SUMA s;
  std::cout << s({2, 4});

}


// CAMBIAR Val POR operator std::vector<int>