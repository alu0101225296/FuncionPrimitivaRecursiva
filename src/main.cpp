#include "../include/pow.hpp"

int main(int argc, char *argv[]) {
  if (argc == 3) {
    POW pow;
    std::cout << "Resultado: " << pow({atol(argv[1]), atol(argv[2])}) << "\n";
  } else {
    std::cout << "Necesita dos argumentos\n"; 
  }
}