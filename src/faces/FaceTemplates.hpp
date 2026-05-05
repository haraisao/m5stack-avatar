#ifndef M5AVATAR_FACES_HPP_
#define M5AVATAR_FACES_HPP_

#include "Eyebrows.hpp"
#include "Eyes.hpp"
#include "Face.h"
#include "Mouths.hpp"

namespace m5avatar {
/**
 * @brief face template for "o_o"
 *
 */
class SimpleFace : public Face {
   public:
    SimpleFace()
        : Face(new RectMouth(50, 90, 4, 60), new BoundingRect(163, 148),
               // right eye, second eye arg is center position of eye in (x,y)
               new EllipseEye(16, 16, false), new BoundingRect(90, 93),
               //  left eye
               new EllipseEye(16, 16, true), new BoundingRect(230, 96),
               //  hide eye brows with setting these height zero
               new EllipseEyebrow(0, 0, false), new BoundingRect(96, 67),
               new EllipseEyebrow(0, 0, true), new BoundingRect(230, 72)) {}
};
/**
 * @brief face template for "OωO" face
 *
 */
class OmegaFace : public Face {
   public:
    OmegaFace()
        : Face(new OmegaMouth(), new BoundingRect(160, 225),
               // right eye, second eye arg is center position of eye in (x, y)
               new EllipseEye(false), new BoundingRect(84, 165),
               //  left eye
               new EllipseEye(true), new BoundingRect(84 + 154, 165),
               //  hide eye brows with setting these height zero
               new EllipseEyebrow(0, 0, false), new BoundingRect(96, 67),
               new EllipseEyebrow(0, 0, true), new BoundingRect(230, 72)) {}
};

class GirlyFace : public Face {
   public:
    GirlyFace()
        : Face(new UShapeMouth(44, 44, 0, 16), new BoundingRect(160, 222),
               // right eye, second eye arg is center position of eye
               new GirlyEye(84, 84, false), new BoundingRect(64, 163),
               //  left eye
               new GirlyEye(84, 84, true), new BoundingRect(256, 163),

               // right eyebrow
               new EllipseEyebrow(36, 20, false),
               new BoundingRect( 84 + 18, 97 + 10),  // (x,y)
                                                    //  left eyebrow
               new EllipseEyebrow(36, 20, true),
               new BoundingRect(200 + 18, 107) ) {}
};

class GirlyFace2 : public Face {
   public:
    GirlyFace2()
        : Face(new UShapeMouth(44, 44, 0, 16), new BoundingRect(160, 222),
               // right eye, second eye arg is center position of eye
               new GirlyEye(84, 84, false), new BoundingRect(64, 163),
               //  left eye
               new GirlyEye(84, 84, true), new BoundingRect(256, 163),

               // right eyebrow
               new BowEyebrow(160, 160, false),
               new BoundingRect(64, 163),  // (x,y)
                                           //  left eyebrow
               new BowEyebrow(160, 160, true), new BoundingRect(256, 163)) {}
};

class PinkDemonFace : public Face {
   public:
    PinkDemonFace()
        : Face(new UShapeMouth(64, 64, 0, 16), new BoundingRect(160, 214),
               // right eye, second eye arg is center position of eye
               new PinkDemonEye(52, 134, false), new BoundingRect(106, 134),
               //  left eye
               new PinkDemonEye(52, 134, true), new BoundingRect(218, 134),

               //  hide eye brows with setting these height zero
               new EllipseEyebrow(15, 0, false), new BoundingRect(96, 67),
               new EllipseEyebrow(15, 0, true), new BoundingRect(230, 72)) {}
};

class DoggyFace : public Face {
   public:
    DoggyFace()
        : Face(new DoggyMouth(50, 90, 4, 60), new BoundingRect(163, 168),
               // right eye, second eye arg is center position of eye
               new DoggyEye(false), new BoundingRect(80, 103),
               //  left eye
               new DoggyEye(true), new BoundingRect(240, 106),
               //  hide eye brows with setting these height zero
               new RectEyebrow(15, 2, false), new BoundingRect(96, 67),
               new RectEyebrow(15, 2, true), new BoundingRect(230, 72)) {}
};

}  // namespace m5avatar

#endif  // M5AVATAR_FACES_HPP_
