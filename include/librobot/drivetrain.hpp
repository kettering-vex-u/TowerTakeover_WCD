#ifndef _DRIVETRAIN_HPP_
#define _DRIVETRAIN_HPP_

#include "main.h"

namespace drivetrain {
    void init();
    void arcadeDrive(double throttle, double rotation);
    void tankDrive(double left, double right);
}

#endif
