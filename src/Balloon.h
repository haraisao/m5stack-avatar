// Copyright (c) Shinya Ishikawa. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.

#ifndef BALLOON_H_
#define BALLOON_H_
#define LGFX_USE_V1
#include <M5Unified.h>
#include "DrawContext.h"
#include "Drawable.h"

#ifndef ARDUINO
#include <string>
typedef std::string String;
#endif  // ARDUINO

const int16_t TEXT_HEIGHT = 8;
const int16_t TEXT_SIZE = 2;
const int16_t MIN_WIDTH = 40;
const int cx = 240;
const int cy = 220;

namespace m5avatar {
class Balloon final : public Drawable {
 private:
   int start_tm = -1;
   String current="";
 public:
  // constructor
  Balloon() = default;
  ~Balloon() = default;
  Balloon(const Balloon &other) = default;
  Balloon &operator=(const Balloon &other) = default;
  void draw(M5Canvas *spi, BoundingRect rect,
            DrawContext *drawContext) override {
    String text = drawContext->getSpeechText();
    text.trim();
    const lgfx::IFont *font = drawContext->getSpeechFont();

    if(current != text){
      start_tm = millis();
      current = text;
    }

    if (text.length() == 0) {
      return;
    }

    int duration = millis() - start_tm;
    ColorPalette* cp = drawContext->getColorPalette();
    uint16_t primaryColor = cp->get(COLOR_BALLOON_FOREGROUND);
    uint16_t backgroundColor = cp->get(COLOR_BALLOON_BACKGROUND);
    //M5.Lcd.setTextSize(TEXT_SIZE);
    //M5.Lcd.setTextDatum(MC_DATUM);
    spi->setTextSize(TEXT_SIZE);
    spi->setTextColor(primaryColor, backgroundColor);
    spi->setTextDatum(MC_DATUM);
    spi->setFont(font);
    //M5.Lcd.setFont(font);
    //int textWidth = M5.Lcd.textWidth(text.c_str());
    int textWidth = spi->textWidth(text.c_str());
    int textHeight = TEXT_HEIGHT * TEXT_SIZE;
    spi->fillEllipse(cx - 20, cy,textWidth + 2, textHeight * 2 + 2,
                     primaryColor);
    spi->fillTriangle(cx - 62, cy - 42, cx - 8, cy - 10, cx - 41, cy - 8,
                      primaryColor);
    spi->fillEllipse(cx - 20, cy, textWidth, textHeight * 2,
                     backgroundColor);
    spi->fillTriangle(cx - 60, cy - 40, cx - 10, cy - 10, cx - 40, cy - 10,
                      backgroundColor);

    int xpos = 320+textWidth/2;;
    if(textWidth > 300){
      xpos -= std::round(duration/5);
      if (xpos < -textWidth/2){
        start_tm = millis();
      }
    }else{
      xpos = cx - textWidth / 6 - 15;
    }
    spi->drawString(text.c_str(), xpos, cy, font);  // Continue printing from new x position
  }
};

}  // namespace m5avatar

#endif  // BALLOON_H_
