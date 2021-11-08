#include "fpr.h"

FPR::FPR() {

}

FPR::~FPR() {

}

float FPR::Z(float n) {
  return 0;
}

float FPR::S(float n) {
  return n++;
}

float FPR::P(std::vector<float> n, int i) {
  return n[i - 1];
}

float FPR::Combinacion(float c1, float c2) {
  
}