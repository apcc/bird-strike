#include <Siv3D.hpp>
#include <common.hpp>
#include <scenes.hpp>

void Main() {
  FontAsset::Register(U"TitleFont", 60, Typeface::Heavy);

  Scene::Resize(Size(1920, 1080));
  Window::Resize(Size(1920, 1080), WindowResizeOption::KeepSceneSize);
  Window::SetStyle(WindowStyle::Sizable);
  Window::SetTitle(U"Bird Strike!");

  App manager;

  registerScenes(manager);

  while (System::Update()) {
    if (!manager.update())
      break;
  }
}
