#pragma once

#include <Siv3D.hpp>
#include <common.hpp>

class Game : public App::Scene {
public:
  Game(const InitData& init);

  void update() override;

  void draw() const override;
};
