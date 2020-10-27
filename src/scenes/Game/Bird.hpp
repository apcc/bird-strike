#pragma once
#include <Siv3D.hpp>
#include "Player.hpp"
#include "Enemy.hpp"

class Bird : public Enemy {
public:
  constexpr static double speed = 0.1;
public:
  Bird();

  void update();

  void draw() const;

  bool shouldBeErased() const;

  double getDepth() const;

  bool collidesWith(const Player& p) const;

  Circle shape() const { return Circle(pos, 20); }

  static int32 getDamage();
};
