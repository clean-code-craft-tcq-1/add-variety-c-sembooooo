#include "test_stub.h"

int Call_AlertTestDouble;
BreachType par_breach;

void AlertTestDouble(BreachType breach)
{
  Call_AlertTestDouble++;
  par_breach = breach;
}

int GetCall_AlertTestDouble(void)
{
  int ret= Call_AlertTestDouble;
  Call_AlertTestDouble = 0;
  return ret;
}

BreachType GetPar_breach(void)
{
  BreachType ret = par_breach;
  par_breach = 0;
  return ret; 
}