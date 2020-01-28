#include "main.h"

using namespace okapi;

const auto WHEEL_DIAMETER = 4_in;
const auto CHASSIS_WIDTH = 11_in;

namespace drivetrain {

	Motor driveFL(DRIVE_FL);
	Motor driveRL(DRIVE_RL);
	Motor driveFR(DRIVE_FR);
	Motor driveRR(DRIVE_RR);

	MotorGroup driveLeft({driveFL, driveRL});
	MotorGroup driveRight({driveFR, driveRR});

	auto drive = ChassisControllerBuilder()
		.withMotors(driveLeft, driveRight)
		.withDimensions(
			AbstractMotor::gearset::green,
			{{WHEEL_DIAMETER, CHASSIS_WIDTH}, imev5GreenTPR}
		)
		.withOdometry()
		.buildOdometry();

	void init() {

	}

	/** arcade drive control:
	 *  left joystick controls throttle,
	 *  right joystick controls rotation
	 */
	void arcadeDrive(double throttle, double rotation) {
		drive->getModel()->arcade(throttle, rotation);
	}

	/** tank drive control:
	 *  left joystick controls left side,
	 *  right joystick controls right side
	 */
	void tankDrive(double left, double right) {
		drive->getModel()->tank(left, right);
	}

	/**
	 * declarations so auton code can be used elsewhere
	 */
	void driveAsync(QLength distance) {
		drive->moveDistanceAsync(distance);
	}

	void driveSync(QLength distance) {
		drive->moveDistance(distance);
	}

	void turnAsync(QAngle angle) {
		drive->turnAngleAsync(angle);
	}

	void turnSync(QAngle angle) {
		drive->turnAngle(angle);
	}

	void waitUntilFinished() {
		drive->waitUntilSettled();
	}

}
