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

struct LogDefinition {

  std::string file;
  std::string mesage;
  int line;
};

class Debuging {

private:
public:
  static void addGeneralLog(std::string file,
                            std::vector<logDefinition> logList) {}

}

#define ADD_GENERAL_LOG(msg) ;

// Test, I don't know what I'm doing

// To do: create the class of debug_sistem.hpp in this file
