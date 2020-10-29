#include "Game.hpp"

Game::Game(const InitData& init) : IScene(init), game_time(true) {
  enemy_timer.set(0s);
  enemy_timer.start();
}

void Game::update() {
  if (player.getHP() <= 0) {
    // TODO: 終了時アニメーション
    game_time.pause();
    changeScene(U"Result");
  }

  if (enemy_timer.reachedZero()) {
    enemies.push_back(std::make_shared<Bird>());
    enemy_timer.set(SecondsF((Random(1.0, 2.0) / 1000 / (game_time.sF() + 1))));
  }

  player.update();
  enemies.each([&](std::shared_ptr<Enemy> e) {
    e->update();
    if (e->collidesWith(this->player)) {
      this->player.decreaseHP(e->getDamage());
    }
  });
  enemies.remove_if([](const std::shared_ptr<Enemy> e) {return e->shouldBeErased(); });
  enemies.sort_by([](const std::shared_ptr<Enemy> a, const std::shared_ptr<Enemy> b) {
    return a->getDepth() > b->getDepth();
  });
}

void Game::draw() const {
  Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

  player.draw();
  enemies.each([](const std::shared_ptr<Enemy> e) { e->draw(); });

  FontAsset(U"TitleFont")(U"{:.1f} s"_fmt(game_time.sF())).draw(Arg::topRight = Vec2(700, 100));
}
