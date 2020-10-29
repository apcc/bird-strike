#include "Bird.hpp"

Bird::Bird() {
  pos = RandomVec2(Scene::Rect());
  depth = 1;
}

void Bird::update() {
  depth -= Scene::DeltaTime() * speed;
}

void Bird::draw() const {
  Circle(pos, 20).draw(Palette::Green.lerp(Palette::White, depth / 2));
}

int32 Bird::getDamage() const {
  return damage;
}
