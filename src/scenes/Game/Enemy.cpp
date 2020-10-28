#include "Enemy.hpp"

Enemy::Enemy() : pos(RandomVec2(Scene::Rect())), depth(1), intersected(false) {}

void Enemy::update() {
  depth -= Scene::DeltaTime() * speed;
}

void Enemy::draw() const {
  Circle(pos, 20).draw(Palette::Red.lerp(Palette::White, depth / 2));
}

bool Enemy::shouldBeErased() const {
  return depth < 0 || intersected;
}

double Enemy::getDepth() const {
  return depth;
}

bool Enemy::collidesWith(const Player& p) {
  return intersected =  (p.shape().intersects(shape()));
}

int32 Enemy::getDamage() {
  return damage;
}
