// Header de sistema de audio

#pragma once
#include "miniaudio.h"
/*
ma_result result;
        ma_engine engine;
        ma_sound sound;

        result = ma_engine_init(NULL, &engine);
        if (result != MA_SUCCESS){
                return result;
        }

        result = ma_sound_init_from_file(&engine,
"assets/audios/RPG_proyecto.mp3", 0, NULL, NULL, &sound); if (result !=
MA_SUCCESS){ return result;
        }

        ma_sound_start(&sound);
*/

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
};
