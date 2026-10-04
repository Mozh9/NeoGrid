/*header de debug_sistem.cpp*/

#pragma once
#include <string>
#include <vector>

#define ADD_GENERAL_LOG(msg)                                                   \
  Debugging::getInstance().addLog(__FILE__, __LINE__, (msg), 1);
#define ADD_INIT_LOG(msg)                                                      \
  Debugging::getInstance().addLog(__FILE__, __LINE__, (msg), 2);
#define ADD_SOUND_LOG(msg)                                                     \
  Debugging::getInstance().addLog(__FILE__, __LINE__, (msg), 3);

struct Log {
  std::string file;
  int line;
  std::string message;
  int type;
};

class Debugging {

private:
  int typeOfDebugging = 3;
  std::vector<Log> logList;
  Debugging() = default;

public:
  Debugging(const Debugging &) = delete;
  Debugging &operator=(const Debugging &) = delete;

  static Debugging &getInstance() {
    static Debugging instance;
    return instance;
  }

  void addLog(std::string file, int line, std::string message, int type);
  void checkWichLogsToPrint(int index, int debugType) const;
  void printLogs() const;
};
