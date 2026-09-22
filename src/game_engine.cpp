
#include "game_engine.hpp"
#include "debug_sistem.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void GameEngine::init() {
  // cout << "[DEBUG] [GameEngine::init] Initializing game" << endl;
  isOn = true;
  // cout << "[DEBUG] [GameEngine::init] isOn = " << isOn << endl;
}

void GameEngine::load() {
  // cout << "[DEBUG] [GameEngine::load] Loading game" << endl;
}

void GameEngine::run() {
  // cout << "[DEBUG] [GameEngine::run] Runing game" << endl;

  while (isOn) {
    // Get player input
    // Process player input
    // Print results

    // cout << "Presiona enter para seguir" << endl;
    cin.get();
    isOn = false;
  }
}

void GameEngine::end() {
  addGeneralLog("[DEBUG] [GameEngine::end] Ending game");
}
