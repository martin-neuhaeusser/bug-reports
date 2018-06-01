#include <cvc4/cvc4.h>
#include <iostream>

using namespace std;
using namespace CVC4;

void test() {
  cout << "creating bit vector representing 1/2 as 32 bit IEEE754" << endl;
  BitVector bv = BitVector("00111111000000000000000000000000");
  cout << "bit vector is " << bv << " with length " << bv.getSize() << endl;

  // CVC4 and SMTLIBv2 expect the significand bit width to include
  // the hidden bit
  int significand_width = 24;
  int exponent_width = 8;
  cout << "creating floating point with " << significand_width << " significand and " << exponent_width << " exponent bits..." << endl;
  FloatingPoint fp = FloatingPoint(exponent_width, significand_width, bv);
  cout << "floating point number is " << fp << endl;
}

int main (int argc, char* argv[]) {
  test();
  cout << "test succeeded" << endl;
}
