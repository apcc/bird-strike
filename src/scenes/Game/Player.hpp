#pragma once
#include <Siv3D.hpp>

class Player final {
  Vec2 pos;
  constexpr static double Speed = 10.0;
  constexpr static int32 size = 20;
  int32 hp = 5;

public:
  Player();

  void update();

  void draw() const;

  Circle shape() const { return Circle(pos, size); }

  void decreaseHP(int32 damage);

  int32 getHP() const;
};
