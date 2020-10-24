#include "Utils.hpp"

void Utils::fullScreenTrigger(bool& isFullScreen) {
  if (!isFullScreen && KeyF11.down()) {
    if (Window::SetFullscreen(true, unspecified, WindowResizeOption::KeepSceneSize))
      isFullScreen = true;
  } else if (isFullScreen && (KeyF11.down() || KeyEscape.down())) {
    if (Window::SetFullscreen(false, unspecified, WindowResizeOption::KeepSceneSize))
      isFullScreen = false;
  }
}
