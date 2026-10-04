// header VideoSystem
#pragma once
#include <string>
#include <vector>

class VideoSystem {
private:
  VideoSystem() {}

public:
  VideoSystem(const VideoSystem &) = delete;
  VideoSystem &operator=(const VideoSystem &) = delete;

  static VideoSystem &get() {
    static VideoSystem instance;
    return instance;
  }

  struct VisualElement {};

  void createVisualElement(std::string elementName);
  void loadTxtToVisualElement(std::string elementName, std::string fileName);
};
