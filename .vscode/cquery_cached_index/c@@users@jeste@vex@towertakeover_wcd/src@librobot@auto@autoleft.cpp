#include "main.h"
#include "librobot/drivetrain.hpp"
#include "librobot/intake.hpp"

using namespace okapi;

void autoLeft() {
    drivetrain::driveAsync(10_in);
    intake::intakeIn(12000);
    drivetrain::waitUntilFinished();
    drivetrain::turnSync(90_deg);
    drivetrain::driveSync(15_in);
}
