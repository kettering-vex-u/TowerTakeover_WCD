#include "main.h"

using namespace okapi;

const double wrist_kP = 0.001;
const double wrist_kI = 0.000;
const double wrist_kD = 0.000;

const double maxVelocity = 1.0;

namespace wrist {

    Motor wristLeft(WRIST_L);
    Motor wristRight(WRIST_R);


    auto wrist = AsyncPosControllerBuilder()
        .withMotor({wristLeft, wristRight})
        .withGains({wrist_kP, wrist_kI, wrist_kD})
        .build();

    void init() {
        wrist->tarePosition();
    }

    void wristUp(double power) {
        wristLeft.moveVoltage(power);
        wristRight.moveVoltage(-power);
    }

    void wristDown(double power) {
        wristLeft.moveVoltage(-power);
        wristRight.moveVoltage(power);
    }

    void wristToPosition(double position, double velocity) {
        wristLeft.moveAbsolute(position, velocity);
        wristRight.moveAbsolute(-position, -velocity);
    }

    void waitUntilFinished() {
        wrist->waitUntilSettled();
    }

    void stopWrist() {
        wristLeft.moveVoltage(0);
        wristRight.moveVoltage(0);
    }

}
