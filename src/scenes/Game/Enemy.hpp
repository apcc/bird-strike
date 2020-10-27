#pragma once
#include <Siv3D.hpp>
#include "Player.hpp"

class Enemy final {
  Vec2 pos;

  double depth;
  constexpr static double speed = 0.1;

public:
  Enemy();

  void update();

  void draw() const;

  bool shouldBeErased() const;

  double getDepth() const;

  bool collidesWith(const Player& p) const;

  Circle shape() const { return Circle(pos, 20); }
};
