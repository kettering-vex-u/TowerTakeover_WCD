#ifndef _DRIVETRAIN_HPP_
#define _DRIVETRAIN_HPP_

#include "main.h"

using namespace okapi;

namespace drivetrain {
    void init();
    void arcadeDrive(double throttle, double rotation);
    void tankDrive(double left, double right);

    void driveAsync(QLength distance);
    void driveSync(QLength distance);

    void turnAsync(QAngle angle);
    void turnSync(QAngle angle);

    void waitUntilFinished();
}

#endif
