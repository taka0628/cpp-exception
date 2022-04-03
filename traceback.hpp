#ifndef ___TRACE_BACK_HPP
#define ___TRACE_BACK_HPP

#define TB_TRACEBACK(using_name)                                               \
  traceback_c using_name(__FILE__, __func__, __LINE__)
#define TB_INVALID_NUM(num) TO_STRING(num), std::to_string(num)

#define TO_STRING(val) #val

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

class traceback_c : public std::exception {
private:
public:
  traceback_c(const std::string &file, const std::string &func,
              const uint &line);
  //   ~traceback_c();
  //   変数名, 内容
  void set_invarid_num(const char *name, const std::string &val);
};

#endif