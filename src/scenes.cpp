#include <scenes.hpp>

App& registerScenes(App& app) {
  app.add<Title>(U"Title");
  app.add<Description>(U"Description");
  app.add<Game>(U"Game");
  app.add<Result>(U"Result");

  return app;
}
