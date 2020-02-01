#include "main.h"

using namespace okapi;

const double pusher_kP = 0.000;
const double pusher_kI = 0.000;
const double pusher_kD = 0.000;

namespace pusher {

    Motor pusherLeft(PUSHER_L);
    Motor pusherRight(PUSHER_R);

    auto pusher = AsyncPosControllerBuilder()
        .withMotor({pusherLeft, pusherRight})
        // .withGains({pusher_kP, pusher_kI, pusher_kD})
        .build();

    void init() {
        pusher->tarePosition();
    }

    void pusherForward(double power) {
        pusherLeft.moveVoltage(power);
        pusherRight.moveVoltage(-power);
    }

    void pusherBackward(double power) {
        pusherLeft.moveVoltage(-power);
        pusherRight.moveVoltage(power);
    }

    void pusherToPosition(double position, double velocity) {
        pusherLeft.moveAbsolute(position, velocity);
        pusherRight.moveAbsolute(-position, -velocity);
    }

    void stopPusher() {
        pusherLeft.moveVoltage(0);
        pusherRight.moveVoltage(0);
    }

}
