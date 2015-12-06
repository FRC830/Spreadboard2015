#include "WPILib.h"

class Robot: public IterativeRobot
{
private:
	static const int FIRST_VICTOR_PWM = 1;
	static const int SECOND_VICTOR_PWM = 2;
	static const int THRID_VICTOR_PWM = 3;
	Victor*victorOne;
	LiveWindow *lw;


	void RobotInit()
	{

		victorOne = new Victor(FIRST_VICTOR_PWM);

		lw = LiveWindow::GetInstance();
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

	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);
