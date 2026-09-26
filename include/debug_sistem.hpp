/*header de debug_sistem.cpp*/

#pragma once
#include <string>

#define ADD_GENERAL_LOG(msg)                                                   \
  Debugging::getInstance().addGeneralLog(__FILE__, __LINE__, (msg))
void addGeneralLog(std::string msg);

struct Log {
  std::string file;
  int line;
  std::string message;
};
