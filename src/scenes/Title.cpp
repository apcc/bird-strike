#include "Title.hpp"
#include <common.hpp>

Title::Title(const InitData& init)
  : IScene(init) {
}

void Title::update() {
  if (KeyAny.down()) {
    changeScene(U"Description");
  }
}

void Title::draw() const {
  Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

  FontAsset(U"TitleFont")(U"bird strike!").drawAt(960, 300);

  FontAsset(U"TitleFont")(U"Press Any Button").drawAt(960, 800, ColorF(1.0, Periodic::Jump0_1(2s)));

  Circle(Cursor::Pos(), 50).draw(Palette::Orange);
}
