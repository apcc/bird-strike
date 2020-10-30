#include "Player.hpp"

Player::Player()
  : pos(Scene::Rect().center()) {
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
  TextureAsset(U"Player1").drawAt(pos);
}

void Player::decreaseHP(int32 damage) {
  hp -= damage;
  Print << hp;
}

int32 Player::getHP() const {
  return hp;
}
