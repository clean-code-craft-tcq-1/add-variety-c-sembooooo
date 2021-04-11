#include "Unit_mocks.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int Call_AlertTestDouble;
BreachType par_breach;

void AlertTestDouble(BreachType breach)
{
  Call_AlertTestDouble++;
  par_breach = breach;
}

int GetCallAlertTestDouble(void)
{
  int ret= Call_AlertTestDouble;
  Call_AlertTestDouble = 0;
  return ret;
}

BreachType GetParbreach(void)
{
  BreachType ret = par_breach;
  par_breach = NORMAL;
  return ret; 
}

void Reset_UnitMockVariables(void)
{
  Call_AlertTestDouble = par_breach =0;
}
