#include <vector>
#include <iostream>
#include <assert.h> 

class FPR {
 protected:
  std::vector<int> arg;
  std::vector<int> result;
 public:
  FPR() {}
  ~FPR() {}
  virtual std::vector<int> base(std::vector<int> n) { return{};}
  virtual std::vector<int> recurrence(std::vector<int> n) { return{};}
  void setArg(std::vector<int> n) {
    arg = n;
  }

  virtual void exec(std::vector<int> n) { 
    int y = n.back(); // las element
    if(y == 0) {  // case base
      result = base(n);
      return;
    } else {
      std::vector<int> tempA = n;
			tempA[tempA.size() - 1] = y - 1;
			std::vector<int> tempB;
      exec(tempA);
			tempB.push_back(result[0]);
      tempB.insert(tempB.end(), tempA.begin(), tempA.end());
			result = recurrence(tempB);
      return;
    }
  }

  FPR operator ()(std::vector<int> arg) {  // gotta try making a copy instead, prolly not gonna work tho
    setArg(arg);
    exec(arg);
    return *this;
  }   

  FPR operator *(FPR op) {  // composicion
    setArg(op);
    exec(op);
    return *this;
    // return *this(op.Val());  no funca la wea esta
  } 

  operator std::vector<int>() {
    return result;
  }

  operator int() {
    return result[0];
  }

  friend std::ostream& operator << (std::ostream& out, const FPR& fpr);
};

std::ostream& operator << (std::ostream& out, const FPR& fpr) {
  if(fpr.result.size() > 1)
    for(auto val : fpr.result)
      out << val << " ";
  else out << fpr.result[0];
  return out;
}


class Z : public FPR { // works
  void exec(std::vector<int> n) {
    result.resize(0); // no me fio
    result.push_back(0);
  }
};

class S : public FPR {  // works
  public:
  void exec(std::vector<int> n) {
    result.resize(0);  // no me fio
    result.push_back(arg[0] + 1);
  }
};

class P : public FPR { // works
 private:
  int index;
 public:
  void exec(std::vector<int> n) {
    result = {n[index - 1]};
  }

  P operator ()(int pos, std::vector<int> arg) {  // probar al final llamar a exec con pos directamente y quitar index
    index = pos;
    exec(arg);
    return *this;
  }
};


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


int main() {
  ADD s;
  std::cout << s({9, 7}) << "\n";

  MULT m;
  std::cout << m({9, 4}) << "\n";

  POW p;
  std::cout << p({4, 8}) << "\n";
}