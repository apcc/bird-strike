#include "Bird.hpp"

Bird::Bird() {
  pos = RandomVec2(Scene::Rect());
  depth = 1;
}

void Bird::update() {
  depth -= Scene::DeltaTime() * speed;
}

void Bird::draw() const {
  Circle(pos, 20).draw(Palette::Red.lerp(Palette::White, depth / 2));
}

bool Bird::shouldBeErased() const {
  return depth < 0;
}

double Bird::getDepth() const {
  return depth;
}

bool Bird::collidesWith(const Player& p) const {
  return (p.shape().intersects(shape()));
}

int32 Bird::getDamage() {
  return damage;
}
