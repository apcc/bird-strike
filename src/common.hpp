#pragma once
#include <Siv3D.hpp>

struct GameData {
  int32 score = 0;
};

using App = SceneManager<String, GameData>;
