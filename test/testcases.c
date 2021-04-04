#include "test_stub.h"
#include "../typewise-alert.c"
#include <assert.h>
#include <string.h>


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

/**
 * Testcase: 
 * Check if Alert is being called in Check and Alert with inferbreach return value 
 **/
static void TC_AlertcallinCheckandAlert(void)
{
  BatteryCharacter battery;
  battery.Alert = &AlertTestDouble;
  checkAndAlert(battery,20.5);
  assert(GetCall_AlertTestDouble() == 1);
  assert(GetPar_breach() == TOO_HIGH);
}

static void TC_Evaluate_BreachTypeToString_conversion(void)
{
  assert(strcmp(BreachTypeToString(TOO_LOW),"too low") == 0);
  assert(strcmp(BreachTypeToString(TOO_HIGH),"too high") == 0);
  assert(strcmp(BreachTypeToString(NORMAL),"normal") == 0);
}

static int IsArg1toPrintfinSendToEmailCorrect(void)
{
  print = &stub_printfInSendToEmail;
  sendToEmail(TOO_LOW);
  return !(strcmp(get_args_printfInSendToEmail(0),"a.b@c.com"));
}

static int IsArg2toPrintfinSendToEmailCorrect(void)
{
  print = &stub_printfInSendToEmail;
  sendToEmail(TOO_LOW);
  return !(strcmp(get_args_printfInSendToEmail(1),"too low"));
}

static void TC_EvaluatePrintfinSendToEmail(void)
{
  assert(print == printf);
  print = &stub_printfInSendToEmail;
  assert(IsArg1toPrintfinSendToEmailCorrect() == 1);
  assert(IsArg2toPrintfinSendToEmailCorrect() == 1);
}


int main()
{
 TC_inferBreach_TOO_LOW(); 
 TC_inferBreach_TOO_HIGH(); 
 TC_inferBreach_NORMAL_equalsTOOLOW();
 TC_inferBreach_NORMAL_equalsTOOHIGH();
 TC_AlertcallinCheckandAlert();
 TC_Evaluate_BreachTypeToString_conversion();
 TC_EvaluatePrintfinSendToEmail();
 return 0;
}