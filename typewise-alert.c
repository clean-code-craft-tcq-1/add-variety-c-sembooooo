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
  switch(breachType) {
    default:
      printf("To: %s\n", recepient);
      printf("Hi, the temperature is %s\n",BreachTypeToString(breachType));
      break;
    case NORMAL:
    /* say if warning thresholds are introduced for which i dont need to print anymsg
    then i can simply add a case statement below normal like
      >>> case NORMAL:
      >>> case LOWERWARNINGTRHESHOLD: 
      >>>  break;
    so error msg doesnt gets printed and it doesnt get clumsier and easier to read
    */
      break;
  }
}


