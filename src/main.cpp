#include "main.h"
#include "librobot/drivetrain.hpp"
#include "librobot/intake.hpp"
#include "librobot/auton.hpp"

using namespace okapi;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();

	drivetrain::init();
	intake::init();

	auton::init();

	pros::lcd::set_text(1, "Hello PROS User!");
	pros::lcd::register_btn1_cb(on_center_button);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
	auton::autonLeft();
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	// pros::Controller master(pros::E_CONTROLLER_MASTER);
	okapi::Controller master(master);

	// initalizing all buttons
	okapi::ControllerButton buttonA(okapi::ControllerDigital::A);
	okapi::ControllerButton buttonB(okapi::ControllerDigital::B);
	okapi::ControllerButton buttonX(okapi::ControllerDigital::X);
	okapi::ControllerButton buttonY(okapi::ControllerDigital::Y);
	// okapi::ControllerButton buttonLB(E_CONTROLLER_DIGITAL_L1);
	// okapi::ControllerButton buttonLT(E_CONTROLLER_DIGITAL_L2);
	// okapi::ControllerButton buttonRB(E_CONTROLLER_DIGITAL_R1);
	// okapi::ControllerButton buttonRT(E_CONTROLLER_DIGITAL_R2);

	// arcade drive variables
	double throttle;
	double rotation;

	// tank drive variables
	// double left;
	// double right;

	while(true) {

		// arcade drive controls
		throttle = master.getAnalog(okapi::ControllerAnalog::leftY);
		rotation = master.getAnalog(okapi::ControllerAnalog::rightX);
		drivetrain::arcadeDrive(throttle, rotation);

		// tank drive controls
		// left = master.getAnalog(okapi::ControllerAnalog::leftY);
		// right = master.getAnalog(okapi::ControllerAnalog::rightY);
		// drive::tankDrive(left, right);

		// controls
		if(buttonA.isPressed()) {
			intake::intakeIn(12000);
		}
		else if(buttonB.isPressed()) {
			intake::intakeOut(12000);
		}
		else {
			intake::stopIntake();
		}

		// wait and give unnecessary time to other tasks
		// motor telemetry, joystick values, etc. update every 10ms
		pros::delay(10);
	}
}
