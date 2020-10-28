#include "Game.hpp"

Game::Game(const InitData& init) : IScene(init), start_time(Scene::Time()) {
  enemy_timer.set(0s);
  enemy_timer.start();
}

void Game::update() {
  if (MouseL.down()) {
    changeScene(U"Result");
  }

  game_time = Scene::Time() - start_time;

  if (enemy_timer.reachedZero()) {
    enemies.emplace_back();
    enemy_timer.set(SecondsF((Random(1.0, 2.0) / 10000)));
  }

  player.update();
  enemies.each([&](Enemy& e) {
    e.update();
    if (e.collidesWith(this->player)) {
      this->player.decreaseHP(e.getDamage());
    }
  });
  enemies.remove_if([](const Enemy& e) { return e.shouldBeErased(); });
  enemies.sort_by([](const Enemy& a, const Enemy& b) { return a.getDepth() > b.getDepth(); });
}

void Game::draw() const {
  Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

  FontAsset(U"TitleFont")(game_time).drawAt(400, 100);

  player.draw();
  enemies.each([](const Enemy& e) { e.draw(); });
}
