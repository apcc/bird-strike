#pragma once

#include <Siv3D.hpp>
#include <common.hpp>

class Result : public App::Scene {
  constexpr const static char32_t* const scoresFile = U"scores.txt";
  Array<int32> scores;
  uint32 rank;
public:
  Result(const InitData& init);

  void update() override;

  void draw() const override;
};
