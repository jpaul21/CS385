#include <iostream>
using namespace std;

//Bitshifting
// << left shift multiplies by 2^n
// >> right shift divides by 2^n
/*
 *  Signed int uses 2's complement
 *   00000101 (5)
 *  +11111111 (invert)
 *  ----------
 *   11111010 (-5)
 *
 *   Right shift:
 *
 *   11111011  (-5)
 *   >> 1 ==
 *   11111101  (?)
 *
 *
 *  Right shift -> numbers truncated towards -infinity
 * -5 >> 1 == -3
 */

/*
 * Bitwise operators
 *
 * & and
 * | or
 * ^ exclusive or
 * ~ not (negation, bit inversion)
 *
 * 13 & 7
 *   00001101  (13)
 *  &00000111  (7)
 *  ---------------
 *   00000101   (5)
 *
 * 13 | 7
 *   00001101  (13)
 * | 00000111  (7)
 * ----------------
 *   00001111  (15)
 *
 * 13 ^ 7
 *   00001101  (13)
 * ^ 00000111  (7)
 *  ---------------
 *   00001010  (10)
 *
 *~13
 *~00001101  (13)
 * ---------------
 *
 *  hgfedcba
 *  00000000   (vector)
 *
 *  "aba"
 *  unsigned int vector = 0;
 *  unsigned int setter;
 *  setter = 1 << ('a' - 'a');
 *  To determine if a character has been seen before, we'll bitwise AND the
 *  vector and setter:
 *
 *  00000000 (vector)
 * &00000001 (setter)
 * ------------------
 *  00000000
 *
 *  00000000 (vector)
 * |00000001 (setter)
 * -------------------
 *  00000001
 *
 *
 *    */



int main(){

}
