#include "Enemy.hpp"

Enemy::Enemy() : pos(RandomVec2(Scene::Rect())), depth(1), intersected(false) {}

bool Enemy::shouldBeErased() const {
  return depth < 0 || intersected;
}


double Enemy::getDepth() const {
  return depth;
}

bool Enemy::collidesWith(const Player& p) {
  return intersected = (p.shape().intersects(shape()) && depth < 0);
}
