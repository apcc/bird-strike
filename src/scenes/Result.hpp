#pragma once

#include <Siv3D.hpp>
#include <common.hpp>

class Result : public App::Scene {
public:
  Result(const InitData& init);

  void update() override;

  void draw() const override;
};
