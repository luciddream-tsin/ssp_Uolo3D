//
// Created by tsin on 22-7-2.
//

#ifndef UOLO3D_TIMER_H
#define UOLO3D_TIMER_H

#include "Object.h"

namespace Uolo3D {

    class Time : public Object {
        UOLO3D_CLASS_INFO(Iime, Object)
    public:
        Time() = delete;
        Time(Context *context);

        void BeginFrame();
        void EndFrame();
        static void Sleep(unsigned mSec);
    };

    class Timer{

    };
    class HiresTimer{
    public:
        HiresTimer();
        void Reset();
        long long GetUSec(bool reset);

    private:
        long long startTime_;

    };

}

#endif //UOLO3D_TIMER_H
