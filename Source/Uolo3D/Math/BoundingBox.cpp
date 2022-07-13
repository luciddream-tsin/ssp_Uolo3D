//
// Created by tsin on 22-7-14.
//

#include "BoundingBox.h"

namespace Uolo3D{
    BoundingBox::BoundingBox() :minBox_(0, 0, 0), maxBox_(0, 0, 0){

    }
    BoundingBox::BoundingBox(vf3 &minBox, vf3 &maxBox) {
        minBox_ = minBox;
        maxBox_ = maxBox;
    }
}