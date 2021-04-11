#include "Unit_mocks.h"
#include "Library_Mocks.h"
#include "../typewise-alert.c"
#include <assert.h>
#include <string.h>


static void Reset_Stubs(void)
{
  Reset_LibraryMockVariables();
  Reset_UnitMockVariables();
}

static void TC_inferBreach_TOO_LOW(void) {
  assert(inferBreach(12.0, 20.0, 30.0) == TOO_LOW);
}

static void TC_inferBreach_TOO_HIGH(void) {
  assert(inferBreach(40.0, 20.0, 30.0) == TOO_HIGH);
}

static void TC_inferBreach_NORMAL_equalsTOOLOW(void)
{
  assert(inferBreach(20.0, 20.0, 30.0) == NORMAL);
}

static void TC_inferBreach_NORMAL_equalsTOOHIGH(void)
{
  assert(inferBreach(20.0, 20.0, 30.0) == NORMAL);
}

static void TC_AlertcallinCheckandAlert(void)
{
  BatteryCharacter battery;
  battery.Alert = &AlertTestDouble;
  checkAndAlert(battery,20.5);
  assert(GetCallAlertTestDouble() == 1);
  assert(GetParbreach() == TOO_HIGH);
}

static void TC_Evaluate_BreachTypeToString_conversion(void)
{
  assert(strcmp(BreachTypeToString(TOO_LOW),"too low") == 0);
  assert(strcmp(BreachTypeToString(TOO_HIGH),"too high") == 0);
  assert(strcmp(BreachTypeToString(NORMAL),"normal") == 0);
}

static void TC_Evaluate_sendToController(void)
{
  Reset_Stubs();
  BatteryCharacter battery;
  battery.Alert = &sendToController;
  checkAndAlert(battery,20.5);
  assert(GetCallCountToSPICommSendSignal()==1);
  assert(GetCommand() == (0xfeed+TOO_HIGH));
  assert(GetDeviceID() == DEVICEID_FAN_ASIC);
}

static void TC_Evaluate_sendToEmail(void)
{
  Reset_Stubs();
  BatteryCharacter battery;
  battery.Alert = &sendToEmail;
  checkAndAlert(battery,20.5);
  assert(strcmp(GetToAddr(),"a.b@c.com")==0);
  assert(strcmp(GetFromAddr(),"b.c@d.com")==0);
  assert(strcmp(GetBody(),"Hi, the temperature is too high") ==0);
  assert(GetCallCountToEmail() ==1);
}

static void TC_Evaluate_sendToEmail_DuringNormal(void)
{
  Reset_Stubs();
  BatteryCharacter battery;
  battery.Threshold.lowerLimit = 20.0;
  battery.Threshold.upperLimit = 30.0;
  battery.Alert = &sendToEmail;
  checkAndAlert(battery,21.0);
  assert(GetCallCountToEmail() ==0);
}

int main()
{
  TC_inferBreach_TOO_LOW(); 
  TC_inferBreach_TOO_HIGH(); 
  TC_inferBreach_NORMAL_equalsTOOLOW();
  TC_inferBreach_NORMAL_equalsTOOHIGH();
  TC_AlertcallinCheckandAlert();
  TC_Evaluate_BreachTypeToString_conversion();
  TC_Evaluate_sendToController();
  TC_Evaluate_sendToEmail();
  TC_Evaluate_sendToEmail_DuringNormal();
 return 0;
}