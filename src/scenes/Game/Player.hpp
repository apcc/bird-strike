#pragma once
#include <Siv3D.hpp>

class Player final {
  Vec2 pos;

public:
  Player();

  void update();

  void draw() const;
};
