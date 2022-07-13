//
// Created by tsin on 22-7-14.
//

#ifndef UOLO3D_BOUNDINGBOX_H
#define UOLO3D_BOUNDINGBOX_H


#include "mathfu/vector.h"

namespace Uolo3D {
    using vf3 = mathfu::Vector<float, 3>;

    class BoundingBox {

    public:
        BoundingBox();
        BoundingBox(vf3& minBox, vf3& maxBox);

    private:
       vf3 minBox_;
       vf3 maxBox_;
    };

}

#endif //UOLO3D_BOUNDINGBOX_H
