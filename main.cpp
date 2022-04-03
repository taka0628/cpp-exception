#include "traceback.hpp"
#include <iostream>

using namespace std;

void a();
void b();
void c();

void a() {
  int a_num = 1;
  try {
    cout << "fn a done" << endl;
    b();
  } catch (const std::exception &e) {
    TB_TRACEBACK(tb);
    tb.set_invarid_num(TB_INVALID_NUM(a_num));
    throw tb;
  }
}

void b() {
  int b_num = 2;
  try {
    cout << "fn b done" << endl;
    c();
  } catch (const std::exception &e) {
    TB_TRACEBACK(tb);
    tb.set_invarid_num(TB_INVALID_NUM(b_num));
    throw tb;
  }
}

void c() {
  cout << "fn c done" << endl;
  int c_num = 3;
  //   traceback_c tb("c_num", to_string(c_num));
  TB_TRACEBACK(tb);
  tb.set_invarid_num(TB_INVALID_NUM(c_num));
  throw tb;
}

int main() {
  try {
    a();
  } catch (const traceback_c &e) {
    cout << "throw catch in main" << endl;
  }
  return 0;
}