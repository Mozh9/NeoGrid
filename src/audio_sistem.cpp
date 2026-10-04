// sistema de audio por miniaudio
#include <string>
#define MINIAUDIO_IMPLEMENTATION
#include "audio_sistem.hpp"
#include "debug_sistem.hpp"
#include "miniaudio.h"

bool AudioSystem::initAudioSystem() {

  result = ma_engine_init(NULL, &engine);
  if (result != MA_SUCCESS) {
    return result;
  }

  ADD_INIT_LOG("Result initAudioSystem = " + std::to_string(result));

  return true;
}

void AudioSystem::destroyAudioSystem() {
  // luego ponerlo
}

bool AudioSystem::startSound() {
  result = ma_sound_init_from_file(&engine, "assets/audios/RPG_proyecto.mp3", 0,
                                   NULL, NULL, &sound);

  if (result != MA_SUCCESS) {
    return result;
  }

  ADD_INIT_LOG("Result init sound from file = " + std::to_string(result));

  ma_sound_start(&sound);

  ADD_SOUND_LOG("intro starting");
  return true;
}
