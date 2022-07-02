//
// Created by tsin on 22-7-2.
//

#include <sys/time.h>
#include "Timer.h"
#include "IO/Log.h"

namespace Uolo3D{


    //------------------------Time--------beg----------------
    Time::Time(Context *context) : Object(context){
    }

    void Time::BeginFrame() {

    }

    void Time::EndFrame() {

    }

    void Time::Sleep(unsigned int mSec) {
        timespec time{static_cast<time_t>(mSec / 1000), static_cast<long>((mSec % 1000) * 1000000)};
        nanosleep(&time, nullptr);
    }
    //------------------------Time--------end----------------


    //-----------------------Timer-----------beg----------
    //-----------------------Timer-----------end----------



    //-----------------------HiresTimer-----------beg----------
    static long long HiresTick(){
        struct timeval time{};
        gettimeofday(&time, nullptr);
        return time.tv_sec * 1000,000LL + time.tv_usec;
    }

    HiresTimer::HiresTimer() {
        Reset();
    }

    long long HiresTimer::GetUSec(bool reset) {

        long long currentTime = HiresTick();
        UOLO3D_LOG_("start"+ to_string(startTime_));
        UOLO3D_LOG_("cutte"+ to_string(currentTime));
        long long elapsedTime = currentTime - startTime_;
        if (reset) startTime_ = currentTime;

        // HiresTick() 的返回值是在一个范围内循环的(0-1000,000/us), 并不是一直叠加(就算不考虑每秒内的us循环, 计算机的最大表示范围Longlong 也会导致循环)
        // 我们假设这个范围的最大值为x, 则会出现这样的情况: 某次Reset的时候, 把startTime_设置为接近x的值, 而在后续的更新中 current 由于
        // 循环从0开始, 则elapsedTime 为负数, 使用以下方法(Note: 当FPS为1刚好, USPF也为1000000, 和currentTime的循环范围大小一样, 功能不生效):
        if (elapsedTime < 0){
            elapsedTime = (1000000LL - startTime_) + currentTime;
        }

        //TODO: add to adjust to elapsed time.
        return elapsedTime;

    }

    void HiresTimer::Reset() {
        startTime_ = HiresTick();
    }

    //-----------------------HiresTimer-----------end----------
}