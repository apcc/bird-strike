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

FilePath inline toResourcePath(FilePath _path) {
  #if SIV3D_PLATFORM(WINDOWS)
  return Resource(_path);
  #else
  return _path;
  #endif
}
