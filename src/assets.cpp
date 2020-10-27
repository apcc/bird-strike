#include "assets.hpp"

void registerFontAssets() {
  const FilePath Cornerstone = U"resources/fonts/Cornerstone.ttf";
  const FilePath Noto_Medium = U"resources/fonts/NotoSansJP-Medium.otf";
  const FilePath Noto_Bold = U"resources/fonts/NotoSansJP-Bold.otf";
  const FilePath Inter_Medium = U"resources/fonts/Inter-Medium.ttf";
  const FilePath Inter_Bold = U"resources/fonts/Inter-Bold.ttf";

  FontAsset::Register(U"TitleFont", 60, toResourcePath(Cornerstone));
  FontAsset::Register(U"Noto-M-24", 24, toResourcePath(Noto_Medium));
  FontAsset::Register(U"Noto-B-24", 24, toResourcePath(Noto_Bold));
  FontAsset::Register(U"Inter-M-24", 24, toResourcePath(Noto_Medium));
  FontAsset::Register(U"Inter-B-24", 24, toResourcePath(Noto_Bold));
}

FilePath inline toResourcePath(FilePath _path) {
  #if SIV3D_PLATFORM(WINDOWS)
  return Resource(_path);
  #else
  return _path;
  #endif
}
