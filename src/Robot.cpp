#include "WPILib.h"
#include "../util/830utilities.h"

class Robot: public IterativeRobot
{
private:
	static const std::vector<int> victor_pins;
	std::vector<Victor*> victors;
	GamepadF310 * pilot;
	Solenoid * piston;

	void RobotInit()
	{
		for_each(victor_pins, [&](int pin) {
			victors.push_back(new Victor(pin));
		});
		pilot = new GamepadF310(0);
		piston = new Solenoid(1);
	}

	void AutonomousInit()
	{

	}

	void AutonomousPeriodic()
	{

	}

	void TeleopInit()
	{

	}

	void TeleopPeriodic()
	{
		for_each(victors, [&](Victor *v) {
			int pin = v->GetChannel();
			switch (pin) {
			case 1:
				v->Set(pilot->LeftY());
				break;
			case 2:
				v->Set(pilot->RightY());
				break;
			case 3:
				v->Set(pilot->DPadY());
				break;
			default:
				break;
			}
		});
		UpdateDashboard();
	}

	void DisabledPeriodic()
	{
		for_each(victors, [&](Victor *v) {
			v->Set(0);
		});
		UpdateDashboard();
	}

	void UpdateDashboard() {
		for_each(victors, [&](Victor *v) {
			SmartDashboard::PutNumber(std::string("Pin ") + std::to_string(v->GetChannel()), v->Get());
		});
	}
};

const std::vector<int> Robot::victor_pins = {1, 2, 3};

START_ROBOT_CLASS(Robot);
