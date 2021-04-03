#include "typewise-alert.h"
#include <stdio.h>
#include <assert.h>

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
  printf("%x : %x\n", header, breachType);
}

char *BreachTypeStr[BreachType_TotalNumber] = {
  "too low",
  "too high",
  "normal"
};

char *BreachTypeToString(BreachType breachType)
{
  assert((breachType < BreachType_TotalNumber)&&(breachType >= NORMAL));
  return BreachTypeStr[breachType];
}

void sendToEmail(BreachType breachType) {
  const char* recepient = "a.b@c.com";
  if(breachType != NORMAL)
  {
    printf("To: %s\n Hi, the temperature is %s\n",
            recepient,
            BreachTypeToString(breachType));
  }
}