#include "Description.hpp"

Description::Description(const InitData& init) : IScene(init) {}

void Description::update() {
  if (MouseL.down()) {
    changeScene(U"Game");
  }
}

void Description::draw() const {
  Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

  FontAsset(U"TitleFont")(U"Description").drawAt(400, 100);

  Circle(Cursor::Pos(), 50).draw(Palette::Orange);
}
