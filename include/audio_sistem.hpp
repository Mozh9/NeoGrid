// Header de sistema de audio

#pragma once
#include "miniaudio.h"

class AudioSistem {

private:
  ma_result result;
  ma_engine engine;
  ma_sound sound;

public:
};
result = ma_engine_init(NULL, &engine);
if (result != MA_SUCCESS) {
  return result;
}

result = ma_sound_init_from_file(&engine, "assets/audios/RPG_proyecto.mp3", 0,
                                 NULL, NULL, &sound);
if (result != MA_SUCCESS) {
  return result;
}

ma_sound_start(&sound);
