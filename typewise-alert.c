#include "typewise-alert.h"
#include <stdio.h>
#include <assert.h>

int (*print)(const char *restrict , ...) = &printf;

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
  print("%x : %x\n", header, breachType);
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
  const char* recepient = "a.b@c.com";
  if(breachType != NORMAL)
  {
    print("To: %s\n Hi, the temperature is %s\n",
            recepient,
            BreachTypeToString(breachType));
  }
}