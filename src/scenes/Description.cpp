#include "Description.hpp"
#include <common.hpp>

Description::Description(const InitData& init) : IScene(init) {}

void Description::update() {
  if (KeyAny.down()) {
    changeScene(U"Game");
  }
}

constexpr const char32_t* const description_content =
  U"迫り来る鳥に当たらないように飛行機を飛ばし続けよう。\n"
  U"ライフがなくなるとゲームオーバーになります。\n"
  U"操作方法: W S A D キーでそれぞれ上下左右\n"
  U"\n"
  U"生き残った時間がスコアになります。\n"
  U"ハイスコアをめざして頑張ろう!\n";

void Description::draw() const {
  RoundRect(100, 100, 1720, 880, 20).draw(ColorF(0, 0.3));

  FontAsset(U"TitleFont")(U"How to play").drawAt(960, 200);

  FontAsset(U"Noto-M-60")(description_content).draw(150, 400);

  Circle(Cursor::Pos(), 50).draw(Palette::Orange);
}
