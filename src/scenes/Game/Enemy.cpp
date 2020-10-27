#include "Enemy.hpp"

Enemy::Enemy() : pos(RandomVec2(Scene::Rect())), depth(1) {}

void Enemy::update() {
  depth -= Scene::DeltaTime() * speed;
}

void Enemy::draw() const {
  Circle(pos, 20).draw(Palette::Red.lerp(Palette::White, depth / 2));
}

bool Enemy::shouldBeErased() const {
  return depth < 0;
}

double Enemy::getDepth() const {
  return depth;
}

bool Enemy::collidesWith(const Player& p) const {
  return (p.shape().intersects(shape()));
}
