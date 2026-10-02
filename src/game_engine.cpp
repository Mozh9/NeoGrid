
#include "game_engine.hpp"
#include "audio_sistem.hpp"
#include "debug_sistem.hpp"
#include <iostream>

using std::cin;

void GameEngine::init() {
  ADD_GENERAL_LOG("Initializing game");
  isOn = true;
  // cout << "[DEBUG] [GameEngine::init] isOn = " << isOn << endl;
  AudioSystem::get().initAudioSystem();
}

void GameEngine::load() { ADD_GENERAL_LOG("Loading game"); }

void GameEngine::run() {
  ADD_GENERAL_LOG("Game Runing");

  while (isOn) {
    // Get player input
    // Process player input
    // Print results (and debuging)
    AudioSystem::get().startSound();
    cin.get();
    isOn = false;
    Debugging::getInstance().printGeneralLogs();
  }
}

void GameEngine::end() {
  ADD_GENERAL_LOG("Game ending");
  AudioSystem::get().startSound();
  // Debugging::getInstance().printGeneralLogs();
}
