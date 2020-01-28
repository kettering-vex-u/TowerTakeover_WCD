#ifndef _INTAKE_HPP
#define _INTAKE_HPP

#include "main.h"

namespace intake {
    void init();
    void intakeIn(double power);
    void intakeOut(double power);
    void stopIntake();
}

#endif
