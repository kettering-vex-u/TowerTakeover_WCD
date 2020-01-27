#include "main.h"
#include "librobot/drivetrain.hpp"
#include "librobot/intake.hpp"

using namespace okapi;

void autoLeft() {
    drive->moveDistanceAsync(10_in);
    intake::intakeIn(12000);
    drive->waitUntilSettled();
    drive->turnAngle(90_deg);
    drive->moveDistance(10_in);
}
