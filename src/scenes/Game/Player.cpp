#include "Player.hpp"

Player::Player()
  : pos(Scene::Rect().center())
  , heartTexture(Emoji(U"❤️")) {
}

void Player::update() {
  if (KeyW.pressed())
    pos += Vec2(0, -Speed);
  if (KeyS.pressed())
    pos += Vec2(0, Speed);

  if (KeyA.pressed())
    pos += Vec2(-Speed, 0);
  if (KeyD.pressed())
    pos += Vec2(Speed, 0);

  Rect playableArea = Scene::Rect();

  playableArea.setSize(Scene::Rect().w - 2*size, Scene::Rect().h - 2*size).setCenter(Scene::Rect().center().asPoint());

  pos.clamp(playableArea);
}

void Player::draw() const {
  int64 const type = Scene::Time()*3*8;

  TextureAsset(U"Player{}"_fmt(type%3)).drawAt(pos);

  for (int32 i = 0; i < hp; ++i) {
    heartTexture.drawAt(Vec2(1300 + 120*i, 100));
  }
}

void Player::decreaseHP(int32 damage) {
  hp -= damage;
}

int32 Player::getHP() const {
  return hp;
}
