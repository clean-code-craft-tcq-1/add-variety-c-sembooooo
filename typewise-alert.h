#pragma once
typedef enum {
  NORMAL,
  TOO_LOW,
  TOO_HIGH,
  BreachType_TotalNumber
} BreachType;

BreachType inferBreach(double value, double lowerLimit, double upperLimit);

typedef struct{
  double upperLimit;
  double lowerLimit;
} Threshold_t;

typedef struct {
  char brand[48];
  Threshold_t Threshold;
  void (*Alert)(BreachType breach);
} BatteryCharacter;

char *BreachTypeToString(BreachType breachType);
void checkAndAlert(BatteryCharacter batteryChar, double temperatureInC);

void sendToController(BreachType breachType);
void sendToEmail(BreachType breachType);
