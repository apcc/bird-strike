#include "Player.hpp"

Player::Player() : pos(0, 0) {}

void Player::update() {
  if (KeyW.pressed())
    pos += Vec2(0, -Speed);
  if (KeyS.pressed())
    pos += Vec2(0, Speed);

  if (KeyA.pressed())
    pos += Vec2(-Speed, 0);
  if (KeyD.pressed())
    pos += Vec2(Speed, 0);

  pos.clamp(Scene::Rect());
}

void Player::draw() const {
  shape().draw(Palette::Cyan);
}
