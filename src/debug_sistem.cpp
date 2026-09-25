/* Hi this is a test to see how lazy nvim works
 * it is preaty cute. Beater than wat I used to
 * work with. The idea is to create a debug
 * sistem that could help us debug certain
 * parts of the code when we need it
 * and other no when we don't need it
 * also like saing in wich part of the code
 * the debuging is happening and all that stuff*/

#include "debug_sistem.hpp"
#include <iostream>
#include <string>
#include <vector>

/* Macros to generte new logs
#define ADD_TEST_LOG(msg)*/
// Test, I don't know what I'm doing

struct Log {

  std::string file;
  int line;
  std::string message;
};

class Debuging {

private:
  std::vector<Log> logList;
  Debuging() = default;

public:
  Debuging(const Debuging &) = delete;
  Debuging &operator=(const Debuging &) = delete;

  static Debuging &getInstance() {
    static Debuging instance;
    return instance;
  }

  void addGeneralLog(std::string file, int line, std::string message) {
    logList.emplace_back(Log{file, line, message});
  }

  void printGeneralLogs() const {
    for (const auto &log : logList) {
      std::cout << log.file << " " << std::to_string(log.line) << " "
                << log.message << "\n";
    }
  }
};

// To do: create the class of debug_sistem.hpp in this file
