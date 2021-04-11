#include "typewise-alert.h"
#include <assert.h>
#include <string.h>
#include "SoCalledEmailLibrary.h"
#include "SoCalledControllerLibrary.h"

BreachType inferBreach(double value, double lowerLimit, double upperLimit) {
  if(value < lowerLimit) {
    return TOO_LOW;
  }
  if(value > upperLimit) {
    return TOO_HIGH;
  }
  return NORMAL;
}

void checkAndAlert(BatteryCharacter batteryChar, double temperatureInC)
{
  assert(batteryChar.Alert != 0);
  BreachType breachType = inferBreach(temperatureInC,
                                      batteryChar.Threshold.lowerLimit,
                                      batteryChar.Threshold.upperLimit);
  batteryChar.Alert(breachType);
}

void sendToController(BreachType breachType) {
  const unsigned short header = 0xfeed;
  SPIComm_SendSignal(DEVICEID_FAN_ASIC, header + breachType);
}

char *BreachTypeStr[BreachType_TotalNumber] = {
  "normal",
  "too low",
  "too high",
  
};

char *BreachTypeToString(BreachType breachType)
{
  assert((breachType < BreachType_TotalNumber)&&(breachType >= NORMAL));
  return BreachTypeStr[breachType];
}

void sendToEmail(BreachType breachType) {
  EmailContent_t EmailContent;
  char message_body[100] = "Hi, the temperature is ";
  EmailContent.toaddr = "a.b@c.com";
  EmailContent.fromaddr = "b.c@d.com";
  if(breachType != NORMAL)
  {
    strcat(message_body,BreachTypeToString(breachType));
    EmailContent.body = message_body;
    Email(EmailContent);
  }
}