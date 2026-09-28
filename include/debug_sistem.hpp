/*header de debug_sistem.cpp*/

#pragma once
#include <string>
#include <vector>

#define ADD_GENERAL_LOG(msg)                                                   \
  Debugging::getInstance().addGeneralLog(__FILE__, __LINE__, (msg))
void addGeneralLog(std::string msg);

struct Log {
  std::string file;
  int line;
  std::string message;
};

class Debugging {

private:
  std::vector<Log> logList;
  Debugging() = default;

public:
  Debugging(const Debugging &) = delete;
  Debugging &operator=(const Debugging &) = delete;

  static Debugging &getInstance() {
    static Debugging instance;
    return instance;
  }

  void addGeneralLog(std::string file, int line, std::string message);

  void printGeneralLogs() const;
};
