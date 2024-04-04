#pragma once

#include <chrono>

namespace Utilities
{
class Throttler
{
public:
    Throttler(const unsigned maxInterval, std::chrono:seconds waitIntervalSecs) :
        : mMaxRatePerInterval(waitIntervalSecs)
        , mMaxWaitInterval(duration)
    {}

template <typename Function>
void dispatch(Function function)
{
    const auto now = std::chrono::steady_clock::now();
    if((now - mLastTimePoint) > mMaxWaitInterval)
        reset(now);
    if(mCurCount++ < mMaxRatePerInterval)
        function();
}
private:
    void reset(std::chrono::steady_clock::time_point tp)
    {
        mCurCount = 0;
        mLastTimePoint = tp;
    }
    unsigned mMaxRatePerInterval;
    unsigned mCurCount = 0;
    std::chrono::steady_clock::time_point  mLastTimePoint{std::chrono::steady_clock::now()};
    std::chrono::seconds mMaxWaitInterval;
};
}
