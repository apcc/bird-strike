#pragma once

#include <Siv3D.hpp>
#include <common.hpp>
#include <memory>
#include "Game/Bird.hpp"
#include "Game/Player.hpp"

class Game : public App::Scene {
  Player player;
  Array < std::shared_ptr<Enemy> > enemies;
  Timer enemy_timer;
  Stopwatch game_time;

public:
  Game(const InitData& init);

  void update() override;

  void draw() const override;
};
