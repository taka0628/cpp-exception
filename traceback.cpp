#include "traceback.hpp"

traceback_c::traceback_c(const std::string &file, const std::string &func,
                         const uint &line) {
  std::cout << "[Traceback] | File: " << file << " | Func: " << func
            << " | Line: " << line << std::endl;
}

void traceback_c::set_invarid_num(const char *name, const std::string &val) {
  std::cout << "\t" << name << ": " << val << std::endl;
}

// template <typename T>
// void traceback_c::invarid_num(const std::string &name, const T &num) {
//   using namespace std;
//   cout << name << ": " << num << endl;
// }