// Copyright (c) Isao Hara. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.

#pragma once
#define LGFX_USE_V1
#include <M5GFX.h>
#include "DrawContext.h"
#include "Drawable.h"

namespace m5avatar {

class Indicator final : public Drawable {
 private:
  const lgfx::IFont *font = nullptr;
  String text="";
  bool flushing = true;

  void drawActiveMark(M5Canvas *spi, uint32_t x, uint32_t y, 
                      uint16_t color, uint16_t bgColor, bool flushing) {
    drawActiveMark(spi, x, y, color,bgColor, 0, flushing);
  }

  void drawActiveMark(M5Canvas *spi, uint32_t x, uint32_t y, 
                      uint16_t color, uint16_t bgColor, float offset, bool flushing) {
    if (text.length() == 0) return;
    spi->setTextDatum(top_left);
    spi->setTextColor(color, bgColor);
    spi->setTextSize(2);
    //spi->fillRect(x, y, w, 20, bgColor);
    if(flushing && std::abs(offset) < 0.5) return;
    //M5_LOGI("Indicator(%d, %d)", x, y);
    if (font){
      spi->drawString(text.c_str(), x, y, font);
    }else{
      spi->drawString(text.c_str(), x, y);
    }
  }


 public:
  // constructor
  Indicator() = default;
  ~Indicator() = default;
  Indicator(const Indicator &other) = default;
  Indicator &operator=(const Indicator &other) = default;
  void setFlushing(bool v){
    this->flushing = v;
  }
  void draw(M5Canvas *spi, BoundingRect rect, DrawContext *ctx) override {
    uint16_t primaryColor = ctx->getColorDepth() == 1 ? 1 : ctx->getColorPalette()->get(COLOR_INFO_FOREGROUND);
    uint16_t bgColor = ctx->getColorDepth() == 1 ? ERACER_COLOR : ctx->getColorPalette()->get(COLOR_INFO_BACKGROUND);
    float offset = ctx->getBreath();
    Expression exp = ctx->getExpression();
    font = ctx->getSpeechFont();
#if 1
    text = ctx->getInfoText();
    if(ctx->getInfoFlushing() == 0 ) {
      setFlushing(false);
    }else{
      setFlushing(true);
    }
    if (text != ""){
      drawActiveMark(spi, 0, 0, primaryColor, bgColor, -offset, this->flushing);
    }
#else
    switch (exp) {
      case Expression::Happy:
        text="Happy";
        drawActiveMark(spi, 0, 0, primaryColor,  TFT_YELLOWGREEN, -offset);
        break;
      case Expression::Doubt:
        text="Doubt";
        drawActiveMark(spi, 0, 0, primaryColor, TFT_AQUAMARINE, -offset);
        break;
      default:
        text="";
        // noop
        break;
    }
#endif
  }
};

}  // namespace m5avatar

