#include "main.h"
#include "librobot/drivetrain.hpp"
#include "librobot/intake.hpp"

using namespace okapi;

namespace auton {

    void init() {}

    void autonLeft() {
        drivetrain::driveSync(10_in);
        // intake::intakeIn(12000);
        drivetrain::waitUntilFinished();
        // intake::stopIntake();
        drivetrain::turnSync(90_deg);
        drivetrain::driveSync(36_in);
        drivetrain::waitUntilFinished();
    }

}
