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

void Debugging::addLog(std::string file, int line, std::string message,
                       int type) {
  logList.emplace_back(Log{file, line, message, type});
}

void Debugging::printGeneralLogs() const {
  for (int i = 0; i <= logList.size() - 1; i++) {

    if (typeOfDebugging == 1 && logList[i].type == 1) {
      std::cout << logList[i].file << " " << logList[i].line << " "
                << logList[i].message << "\n";
    }
  }
}

// To do: create the class of debug_sistem.hpp in this file
