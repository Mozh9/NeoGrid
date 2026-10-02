// Header de sistema de audio

#pragma once
#include "miniaudio.h"

class AudioSystem {

private:
  ma_result result;
  ma_engine engine;
  ma_sound sound;

  AudioSystem() {}

public:
  AudioSystem(const AudioSystem &) = delete;
  AudioSystem &operator=(const AudioSystem &) = delete;

  static AudioSystem &get() {
    static AudioSystem instance;
    return instance;
  }

  bool initAudioSystem();
  void destroyAudioSystem();

  int startSound();
};
