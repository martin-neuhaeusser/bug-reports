#include <cvc4/cvc4.h>
#include <iostream>

using namespace std;
using namespace CVC4;

void test () {
  // CVC4 and SMTLIBv2 expect the significand bit width to include
  // the hidden bit
  int significand_width = 24;
  int exponent_width = 8;
  cout << "creating single precision 32 bit (significand with "
       << significand_width
       << " and "
       << exponent_width
       << " bits) floating point size" << endl;
  FloatingPointSize sz = FloatingPointSize(exponent_width, significand_width);

  // standard rounding mode
  cout << "creating rounding mode instance (nearest even)" << endl;
  RoundingMode rm = RoundingMode::roundNearestTiesToEven;

  // 1/2
  cout << "constructing rational 1/2" << endl;
  Rational two = Rational(1, 2);

  // floating point from rational
  cout << "constructing floating point from rational " << two << endl;
  FloatingPoint fp = FloatingPoint(sz, rm, two);

  cout << "resulting floating point number is " << fp << endl;
}

int main (int argc, char* argv[]) {
  test ();
  cout << "test succeeded" << endl;
}
