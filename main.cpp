#include <string>
#include <iostream>
#include <thread>
#include "system.h"

doubleBuffer <int> soDaq2Det;
doubleBuffer <int> soDet2Res;

int main (void)
{
    daq oDaq;
    detector oDetector;
    result oResult;

    // initialize
    oDaq.initBuf(soDaq2Det);
    oDetector.initBuf(soDaq2Det,soDet2Res);
    oResult.initBuf(soDaq2Det);

    thread t1 = oDaq.createThread();
    thread t2 = oDetector.createThread();
    thread t3 = oResult.createThread();

    t1.join();
    t2.join();
    t3.join();
}
