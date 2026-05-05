// Copyright (c) Shinya Ishikawa. All rights reserved.
// Licensed under the MIT license. See LICENSE file in the project root for full
// license information.

#ifndef FACES_OLEDFACE_H_
#define FACES_OLEDFACE_H_

#include <M5Unified.h> // TODO(meganetaaan): include only the Sprite function not a whole library
#include "../BoundingRect.h"
#include "../DrawContext.h"
#include "../Drawable.h"

namespace m5avatar {
class OledFace : public Face {
 public:
  OledFace()
      : Face(new Mouth(50, 90, 4, 60), new BoundingRect(163, 168),
             new Eye(8, false), new BoundingRect(80, 103),
             new Eye(8, true), new BoundingRect(240, 106),
             new Eyeblow(15, 2, false), new BoundingRect(96, 67),
             new Eyeblow(15, 2, true), new BoundingRect(230, 72)) {}
};

}  // namespace m5avatar

#endif  // FACES_OLEDFACE_H_

