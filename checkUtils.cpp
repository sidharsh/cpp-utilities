#include <iostream>
#include <include/throttler.h>
#include <chrono>
#include <thread>

using namespace std;

int isThrottled = 1;

int main()
{
    SS::Throttler th1(1, std::chrono::seconds(5));
    auto dispatchF = [&] {
        cout << "Throttled now.. sleeping 1 sec" << endl;
        isThrottled = 0;
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    };

    for(;;)
    {
        if(isThrottled = 1)
            th1.dispatch(dispatchF);
        if(!isThrottled)
            isThrottled = 1;
    }
}
