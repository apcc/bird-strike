#pragma once
#include <Siv3D.hpp>

class Player final {
  Vec2 pos;
  constexpr static double Speed = 10.0;

public:
  Player();

  void update();

  void draw() const;

  Circle shape() const { return Circle(pos, 20); }
};
