#pragma once
#include <Siv3D.hpp>

class Enemy final {
  Vec2 pos;
  int depth;

public:
  Enemy();

  void update();

  void draw() const;
};
