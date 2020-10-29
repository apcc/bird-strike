#include "Result.hpp"

Result::Result(const InitData& init)
  : IScene(init) {
  {
    const int32 score = getData().score;

    TextReader reader(scoresFile);
    {
      scores.push_back(score);
      String line;

      while(reader.readLine(line)) {
        scores.push_back(ParseOr<int32>(line, 0));
      }
      scores.sort();
      rank = scores.end() - upper_bound(scores.begin(), scores.end(), score) + 1;
      scores.reverse();
    }
    TextWriter writer(scoresFile, OpenMode::Append);
    writer.writeln(Format(score));
  }
}

void Result::update() {
  if (MouseL.down()) {
    changeScene(U"Title");
  }
}

void Result::draw() const {
  Scene::SetBackground(ColorF(0.3, 0.4, 0.5));

  FontAsset(U"Cornerstone-120")(U"Score: {}"_fmt(getData().score)).draw(
      Arg::topLeft = Vec2(100, 400));

  FontAsset(U"Cornerstone-120")(U"Rank: {}"_fmt(rank)).draw(
      Arg::topLeft = Vec2(100, 600));

  auto rankingRect = FontAsset(U"Cornerstone-60")(U"Ranking").draw(
      Arg::topCenter = Vec2(1440, 250));

  rankingRect.bottom().draw(2.0, Palette::White);

  bool reachedCurrent = 0;
  for (uint32 i = 0; i < 5; ++i) {
    if (scores.size() <= i) break;

    const ColorF color = (!reachedCurrent && scores[i] == getData().score) ? Palette::Yellow : Palette::White;
    if (scores[i] == getData().score) reachedCurrent = 1;

    FontAsset(U"Cornerstone-60")(U"{}."_fmt(i + 1)).draw(
        Arg::topRight = Vec2(1300, 400 + 100*i), color);

    FontAsset(U"Cornerstone-60")(U"{}"_fmt(scores[i])).draw(
        Arg::topRight = Vec2(1600, 400 + 100*i), color);
  }


  Circle(Cursor::Pos(), 50).draw(Palette::Orange);
}
