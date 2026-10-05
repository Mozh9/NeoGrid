// header VideoSystem
#pragma once
#include <string>
#include <vector>

class GameElement {
private:
public:
  GameElement() {}

  struct VisualElement {};

  void createVisualElement(std::string elementName);
  void loadTxtToVisualElement(std::string elementName, std::string fileName);
};
