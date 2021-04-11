/**
 * This creates a simulation environment to check the execution of our unit
 * by "STUBBING" the library functions.
 */



#include "../typewise-alert.c"

static void SIM_BatteryWithSendToEmail_BreachNORMAL(void)
{
  BatteryCharacter battery;
  battery.Threshold.lowerLimit = 20.0;
  battery.Threshold.upperLimit = 30.0;
  battery.Alert = &sendToEmail;
  checkAndAlert(battery,20.5);
}

static void SIM_BatteryWithSendToEmail(void)
{
    BatteryCharacter battery;
    battery.Alert = &sendToEmail;
    battery.Threshold.lowerLimit = 30.0;
    battery.Threshold.upperLimit = 60.0;
    checkAndAlert(battery,20.5);
}

static void SIM_BatteryWithSendToController(void)
{
    BatteryCharacter battery;
    battery.Alert = &sendToController;
    checkAndAlert(battery,20.5);
}


int main()
{
    SIM_BatteryWithSendToEmail_BreachNORMAL();
    SIM_BatteryWithSendToEmail();
    SIM_BatteryWithSendToController();
    return 0;
}