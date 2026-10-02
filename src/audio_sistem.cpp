// sistema de audio por miniaudio
#define MINIAUDIO_IMPLEMENTATION
#include "audio_sistem.hpp"
#include "miniaudio.h"

bool AudioSystem::initAudioSystem() {
  result = ma_engine_init(NULL, &engine);
  if (result != MA_SUCCESS) {
    return result;
  }

  return true;
}

void AudioSystem::destroyAudioSystem() {
  // luego ponerlo
}

int AudioSystem::startSound() {
  result = ma_sound_init_from_file(&engine, "assets/audios/RPG_proyecto.mp3", 0,
                                   NULL, NULL, &sound);

  if (result != MA_SUCCESS) {
    return result;
  }

  ma_sound_start(&sound);

  return 1;
}
