#include "assets.hpp"

void registerFontAssets() {
  const String Cornerstone = U"src/assets/fonts/Cornerstone.ttf";
  const String Noto_Medium = U"src/assets/fonts/NotoSansJP-Medium.otf";
  const String Noto_Bold = U"src/assets/fonts/NotoSansJP-Bold.otf";
  const String Inter_Medium = U"src/assets/fonts/Inter-Medium.ttf";
  const String Inter_Bold = U"src/assets/fonts/Inter-Bold.ttf";

  FontAsset::Register(U"TitleFont", 60, Resource(Cornerstone));
  FontAsset::Register(U"Noto-M-24", 24, Resource(Noto_Medium));
  FontAsset::Register(U"Noto-B-24", 24, Resource(Noto_Bold));
  FontAsset::Register(U"Inter-M-24", 24, Resource(Noto_Medium));
  FontAsset::Register(U"Inter-B-24", 24, Resource(Noto_Bold));
}
