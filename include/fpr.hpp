#pragma once
#include <vector>
#include <iostream>

class FPR {
 protected:
  std::vector<long int> arg;
  std::vector<long int> result;

 public:
  FPR() {}
  ~FPR() {}
  virtual std::vector<long int> base(std::vector<long int> n) { return{};}
  virtual std::vector<long int> recurrence(std::vector<long int> n) { return{};}
  void setArg(std::vector<long int> n) { arg = n;}
  virtual void exec(std::vector<long int> n);
  FPR operator ()(std::vector<long int> arg); // deberia crear copia mejor pero idk no hay tiempo
  FPR operator *(FPR op);
  operator std::vector<long int>() { return result;}
  operator long int() { return result[0];}
  friend std::ostream& operator << (std::ostream& out, const FPR& fpr);
};

void FPR::exec(std::vector<long int> n) { 
    long int y = n.back(); // last element
    if(y == 0) {  // case base
      result = base(n);
      return;
    } else {
      std::vector<long int> tempA = n;
      tempA[tempA.size() - 1] = y - 1;
      std::vector<long int> tempB;
      exec(tempA);
      tempB.push_back(result[0]);
      tempB.insert(tempB.end(), tempA.begin(), tempA.end());
      result = recurrence(tempB);
      return;
    }
  }

FPR FPR::operator ()(std::vector<long int> arg) {
    setArg(arg);
    exec(arg);
    return *this;
}  

FPR FPR::operator *(FPR op) {  // composicion
    setArg(op);
    exec(op);
    return *this;
    // return *this(op.Val());  no sirve
} 

std::ostream& operator << (std::ostream& out, const FPR& fpr) {
  if(fpr.result.size() > 1)
    for(auto val : fpr.result)
      out << val << " ";
  else out << fpr.result[0];
  return out;
}