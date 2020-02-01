#ifndef _WRIST_HPP_
#define _WRIST_HPP_

#include "main.h"

namespace wrist {
    void init();
    void wristUp(double power);
    void wristDown(double power);
    void wristToPosition(double target);
    void waitUntilFinished();
    void stopWrist();
}

#endif
