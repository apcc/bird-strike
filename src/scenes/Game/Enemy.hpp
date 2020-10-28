#pragma once
#include <Siv3D.hpp>
#include "Player.hpp"

class Enemy {
protected:
  Vec2 pos;

  double depth;
  constexpr static double speed = 0.1;
  constexpr static int32 damage = 1;
  bool intersected;

public:
  Enemy();

  virtual void update() = 0;

  virtual void draw() const = 0;
  
  bool shouldBeErased() const;

  double getDepth() const;

  bool collidesWith(const Player& p);

  virtual Circle shape() const = 0;

  virtual int32 getDamage() const = 0;
};
