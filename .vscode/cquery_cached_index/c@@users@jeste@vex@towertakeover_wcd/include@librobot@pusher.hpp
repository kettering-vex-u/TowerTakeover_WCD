#ifndef _PUSHER_HPP_
#define _PUSHER_HPP_

#include "main.h"

namespace pusher {
    void init();
    void pusherForward(double power);
    void pusherBackward(double power);
    void pusherToPosition(double position, double velocity);
    void waitUntilFinished();
    void stopPusher();
}

#endif
