#pragma once
#include <Siv3D.hpp>
#include "Player.hpp"

class Enemy {
protected:
  Vec2 pos;

  double depth;
  constexpr static double speed = 0.1;
  constexpr static int32 damage = 1;

public:
  Enemy();

  virtual void update();

  virtual void draw() const;
  
  bool shouldBeErased() const;

  double getDepth() const;

  virtual bool collidesWith(const Player& p) const;

  virtual Circle shape() const { return Circle(pos, 20); }

  static int32 getDamage();
};
