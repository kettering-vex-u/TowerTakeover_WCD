#include "main.h"

using namespace okapi;

namespace intake {

    Motor intakeL(INTAKE_L);
    Motor intakeR(INTAKE_R);

    void init() {}

    void intakeIn(double power) {
        intakeL.moveVoltage(power);
        intakeR.moveVoltage(-power);
    }

    void intakeOut(double power) {
        intakeL.moveVoltage(-power);
        intakeR.moveVoltage(power);
    }

    void stopIntake() {
        intakeL.moveVoltage(0);
        intakeR.moveVoltage(0);
    }
}
