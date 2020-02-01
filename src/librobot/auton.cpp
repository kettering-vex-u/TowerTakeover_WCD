#include "main.h"
#include "librobot/drivetrain.hpp"
#include "librobot/intake.hpp"
#include "librobot/wrist.hpp"
#include "librobot/pusher.hpp"

using namespace okapi;

namespace auton {

    void init() {}

    void autonLeft() {

        // pop the tray and intake out
        wrist::wristToPosition(0);
        intake::intakeOut(6000);
        wrist::waitUntilFinished();

        // drive forward and intake cubes
        drivetrain::driveAsync(24_in);
        intake::intakeIn(12000);
        drivetrain::waitUntilFinished();
        intake::stopIntake();

        // turn after grabbing cubes to grab more cubes
        drivetrain::turnSync(135_deg);
        drivetrain::driveSync(36_in);
        drivetrain::waitUntilFinished();
    }

    void autonRight() {

        // pop the tray and intake out
        wrist::wristToPosition(0);
        intake::intakeOut(6000);
        wrist::waitUntilFinished();

        // drive forward and intake cubes
        drivetrain::driveAsync(24_in);
        intake::intakeIn(12000);
        drivetrain::waitUntilFinished();
        intake::stopIntake();

        // turn after grabbing cubes to grab more cubes
        drivetrain::turnSync(135_deg);
        drivetrain::driveSync(36_in);
        drivetrain::waitUntilFinished();
    }

}
