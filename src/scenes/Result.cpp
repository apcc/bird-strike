#include "Result.hpp"

Result::Result(const InitData& init)
  : IScene(init) {
}

void Result::update() {
  if (MouseL.down()) {
    changeScene(U"Title");
  }
}

void Result::draw() const {
  Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

  FontAsset(U"Cornerstone-120")(U"Score: {}"_fmt(getData().score)).draw(
      Arg::topCenter = Vec2(960, 200));

  Circle(Cursor::Pos(), 50).draw(Palette::Orange);
}
