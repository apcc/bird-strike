#include "assets.hpp"

void registerFontAssets() {
  const FilePath Cornerstone = U"resources/fonts/Cornerstone.ttf";
  const FilePath Noto_Medium = U"resources/fonts/NotoSansJP-Medium.otf";
  const FilePath Noto_Bold = U"resources/fonts/NotoSansJP-Bold.otf";
  const FilePath Inter_Medium = U"resources/fonts/Inter-Medium.ttf";
  const FilePath Inter_Bold = U"resources/fonts/Inter-Bold.ttf";

  FontAsset::Register(U"TitleFont", 100, toResourcePath(Cornerstone));
  FontAsset::Register(U"Noto-M-60", 60, toResourcePath(Noto_Medium));
  FontAsset::Register(U"Noto-B-60", 60, toResourcePath(Noto_Bold));
  FontAsset::Register(U"Inter-M-60", 60, toResourcePath(Noto_Medium));
  FontAsset::Register(U"Inter-B-60", 60, toResourcePath(Noto_Bold));
  FontAsset::Register(U"Cornerstone-60", 60, toResourcePath(Cornerstone));
  FontAsset::Register(U"Cornerstone-120", 120, toResourcePath(Cornerstone));
}

void registerTextureAssets() {
  const FilePath Player_0 = U"resources/images/player/player0.png";
  const FilePath Player_1 = U"resources/images/player/player1.png";
  const FilePath Player_2 = U"resources/images/player/player2.png";
  const FilePath Plane_0 = U"resources/images/plane/plane0.png";
  const FilePath Plane_1 = U"resources/images/plane/plane1.png";
  const FilePath Plane_2 = U"resources/images/plane/plane2.png";
  const FilePath Bird_0 = U"resources/images/bird/bird0.png";
  const FilePath Bird_1 = U"resources/images/bird/bird1.png";
  const FilePath Bird_2 = U"resources/images/bird/bird2.png";

  TextureAsset::Register(U"Player0", toResourcePath(Player_0));
  TextureAsset::Register(U"Player1", toResourcePath(Player_1));
  TextureAsset::Register(U"Player2", toResourcePath(Player_2));
  TextureAsset::Register(U"Plane0", toResourcePath(Plane_0));
  TextureAsset::Register(U"Plane1", toResourcePath(Plane_1));
  TextureAsset::Register(U"Plane2", toResourcePath(Plane_2));
  TextureAsset::Register(U"Bird0", toResourcePath(Bird_0));
  TextureAsset::Register(U"Bird1", toResourcePath(Bird_1));
  TextureAsset::Register(U"Bird2", toResourcePath(Bird_2));
}


FilePath inline toResourcePath(FilePath _path) {
  #if SIV3D_PLATFORM(WINDOWS)
  return Resource(_path);
  #else
  return _path;
  #endif
}
