#pragma once
#include <Siv3D.hpp>
#include "Player.hpp"
#include "Enemy.hpp"

class Bird : public Enemy {
public:
  constexpr static double speed = 0.1;
public:
  Bird();

  void update() override;

  void draw() const override;

  Circle shape() const override { return Circle(pos, 40); }

  int32 getDamage() const override;
};
