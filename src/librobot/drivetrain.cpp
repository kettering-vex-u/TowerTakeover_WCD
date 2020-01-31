#include "main.h"

using namespace okapi;

const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 14_in;

namespace drivetrain {

	Motor driveLeft(DRIVE_L, false, AbstractMotor::gearset::green,
		 			AbstractMotor::encoderUnits::degrees);
	Motor driveRight(DRIVE_R, true, AbstractMotor::gearset::green,
		 			 AbstractMotor::encoderUnits::degrees);

	auto drive = ChassisControllerBuilder()
		.withMotors(driveLeft, driveRight)
		.withDimensions(
			AbstractMotor::gearset::green,
			{{WHEEL_DIAMETER, CHASSIS_WIDTH}, imev5GreenTPR}
		)
		.withOdometry()
		.buildOdometry();

	void init() {}

	/** arcade drive control:
	 *  left joystick controls throttle,
	 *  right joystick controls rotation
	 */
	void arcadeDrive(double throttle, double rotation) {
		drive->setMaxVelocity(200);
		drive->getModel()->arcade(pow(throttle, 3), pow(rotation, 3));
	}

	/** tank drive control:
	 *  left joystick controls left side,
	 *  right joystick controls right side
	 */
	void tankDrive(double left, double right) {
		drive->getModel()->tank(pow(left, 3), pow(right, 3));
	}

	/**
	 * declarations so auton code can be used elsewhere
	 */
	void driveAsync(QLength distance) {
		drive->setMaxVelocity(150);
		drive->moveDistanceAsync(distance);
	}

	void driveSync(QLength distance) {
		drive->setMaxVelocity(150);
		drive->moveDistance(distance);
	}

	void turnAsync(QAngle angle) {
		drive->setMaxVelocity(150);
		drive->turnAngleAsync(angle);
	}

	void turnSync(QAngle angle) {
		drive->setMaxVelocity(150);
		drive->turnAngle(angle);
	}

	void waitUntilFinished() {
		drive->waitUntilSettled();
	}

	void stopDrive() {
		drive->stop();
	}

}
