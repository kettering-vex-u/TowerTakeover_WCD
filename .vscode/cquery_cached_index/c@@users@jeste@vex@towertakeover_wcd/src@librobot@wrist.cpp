#include "main.h"

using namespace okapi;

const double wrist_kP = 0.500;
const double wrist_kI = 0.000;
const double wrist_kD = 0.100;

namespace wrist {

    Motor wristL(WRIST_L);
    Motor wristR(WRIST_R);

    auto wristLeft = AsyncPosControllerBuilder()
        .withMotor(wristL)
        // .withGains({wrist_kP, wrist_kI, wrist_kD})
        .build();

    auto wristRight = AsyncPosControllerBuilder()
        .withMotor(wristR)
        // .withGains({wrist_kP, wrist_kI, wrist_kD})
        .build();

    void init() {
        wristLeft->tarePosition();
        wristRight->tarePosition();
    }

    void wristUp(double power) {
        wristL.moveVoltage(power);
        wristR.moveVoltage(-power);
    }

    void wristDown(double power) {
        wristL.moveVoltage(-power);
        wristR.moveVoltage(power);
    }

    void wristToPosition(double target) {
        wristLeft->setTarget(target);
        wristRight->setTarget(target);
    }

    void waitUntilFinished() {
        wristLeft->waitUntilSettled();
        wristRight->waitUntilSettled();
    }

    void stopWrist() {
        wristL.moveVoltage(1750);
        wristR.moveVoltage(-1750);
    }

}
