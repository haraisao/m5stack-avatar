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

  void drawActiveMark(M5Canvas *spi, uint32_t x, uint32_t y, uint32_t w,
                      uint16_t color) {
    drawActiveMark(spi, x, y, w, color, 0);
  }

  void drawActiveMark(M5Canvas *spi, uint32_t x, uint32_t y, uint32_t w,
                      uint16_t color, float offset) {
    spi->fillRect(x, y, w, 10, color);
    if (font){
      spi->drawString("Active", x, y, font);
    }else{
      spi->drawString("Active", x, y);
    }
  }


 public:
  // constructor
  Indicator() = default;
  ~Indicator() = default;
  Indicator(const Indicator &other) = default;
  Indicator &operator=(const Indicator &other) = default;
  void draw(M5Canvas *spi, BoundingRect rect, DrawContext *ctx) override {
    uint16_t primaryColor = ctx->getColorDepth() == 1 ? 1 : ctx->getColorPalette()->get(COLOR_PRIMARY);
    uint16_t bgColor = ctx->getColorDepth() == 1 ? ERACER_COLOR : ctx->getColorPalette()->get(COLOR_BACKGROUND);
    float offset = ctx->getBreath();
    Expression exp = ctx->getExpression();
    font = ctx->getSpeechFont();
    switch (exp) {
      case Expression::Happy:
        drawActiveMark(spi, 0, 0, 7, primaryColor, -offset);
        break;
      default:
        // noop
        break;
    }
  }
};

}  // namespace m5avatar

