// Copyright (c) Shinya Ishikawa. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.

#include "BoundingRect.h"

namespace m5avatar {
BoundingRect::BoundingRect(int16_t x, int16_t y)
    : BoundingRect(x, y, 0, 0) {}

BoundingRect::BoundingRect(int16_t x, int16_t y, int16_t width,
                           int16_t height)
    : top{y}, left{x}, width{width}, height{height} {}

int16_t BoundingRect::getTop() { return top; }

int16_t BoundingRect::getLeft() { return left; }

int16_t BoundingRect::getRight() { return left + width; }

int16_t BoundingRect::getBottom() { return top + height; }

int16_t BoundingRect::getCenterX() { return left + width / 2; }

int16_t BoundingRect::getCenterY() { return top + height / 2; }

int16_t BoundingRect::getWidth() { return width; }

int16_t BoundingRect::getHeight() { return height; }

void BoundingRect::setPosition(int16_t x, int16_t y) {
  this->top = y;
  this->left = x;
}

void BoundingRect::shift(int16_t dx, int16_t dy) {
  this->top += dy;
  this->left += dx;
}

void BoundingRect::setSize(int16_t width, int16_t height) {
  this->width = width;
  this->height = height;
}
}  // namespace m5avatar
