// Header de sistema de audio

#pragma once
#include "miniaudio.h"

class AudioSystem {

private:
  AudioSystem() {}

public:
  AudioSystem(const AudioSystem &) = delete;
  AudioSystem &operator=(const AudioSystem &) = delete;

  static AudioSystem &get() {
    static AudioSystem instance;
    return instance;
  }
};
