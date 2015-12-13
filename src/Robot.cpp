#include "WPILib.h"
#include "../util/830utilities.h"
#include <map>

class Robot: public IterativeRobot
{
private:
	static const int FIRST_VICTOR_PWM = 1;
	static const int SECOND_VICTOR_PWM = 2;
	static const int THRID_VICTOR_PWM = 3;

	Victor * victorOne;
	Victor * victorTwo;
	Victor * victorThree;
	GamepadF310 * pilot;


	void RobotInit()
	{

		victorOne = new Victor(FIRST_VICTOR_PWM);
		victorTwo = new Victor(SECOND_VICTOR_PWM);
		victorThree = new Victor(THRID_VICTOR_PWM);
		pilot = new GamepadF310(0);
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
		victorOne->Set(pilot->LeftY());
		SmartDashboard::PutNumber("left y", pilot->LeftY());
		SmartDashboard::PutNumber("victor channel", victorOne->GetChannel());
		SmartDashboard::PutNumber("victor value", victorOne->Get());
	}

	void TestPeriodic()
	{
	}
};

START_ROBOT_CLASS(Robot);
