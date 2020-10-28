#pragma once

#include <Siv3D.hpp>
#include <common.hpp>
#include "Game/Bird.hpp"
#include "Game/Player.hpp"

class Game : public App::Scene {
  Player player;
  Array<Enemy> enemies;
  Timer enemy_timer;

public:
  Game(const InitData& init);

  void update() override;

  void draw() const override;
};
