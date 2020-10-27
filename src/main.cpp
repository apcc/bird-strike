#include <Siv3D.hpp>
#include <common.hpp>
#include <scenes.hpp>
#include <utils.hpp>
#include <assets.hpp>

void Main() {
  Scene::Resize(Size(1920, 1080));
  Window::Resize(Size(1920, 1080), WindowResizeOption::KeepSceneSize);
  Window::SetStyle(WindowStyle::Sizable);
  Window::SetTitle(U"Bird Strike!");

  // disable closing app with Esc
  System::SetTerminationTriggers(UserAction::CloseButtonClicked);

  App manager;
  bool isFullScreen = false;

  registerFontAssets();
  registerScenes(manager);

  while (System::Update()) {
    Utils::fullScreenTrigger(isFullScreen);
    if (!manager.update())
      break;
  }
}
