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
  return !(strcmp(get_args_printfInSendToEmail(0),"To: %s\n Hi, the temperature is %s\n"));
}


static int IsArg2toPrintfinSendToEmailCorrect(void)
{
  print = &stub_printfInSendToEmail;
  sendToEmail(TOO_LOW);
  return !(strcmp(get_args_printfInSendToEmail(1),"a.b@c.com"));
}

static int IsArg3toPrintfinSendToEmailCorrect(void)
{
  print = &stub_printfInSendToEmail;
  sendToEmail(TOO_LOW);
  return !(strcmp(get_args_printfInSendToEmail(2),"too low"));
}

static void TC_EvaluatePrintfParametersinSendToEmail(void)
{
  assert(print == printf);
  print = &stub_printfInSendToEmail;
  assert(IsArg1toPrintfinSendToEmailCorrect() == 1);
  assert(IsArg2toPrintfinSendToEmailCorrect() == 1);
  assert(IsArg3toPrintfinSendToEmailCorrect() == 1);
  print = printf;
}

static void TC_SendToEmail_duringNORMAL(void)
{
  Reset_teststubs();
  print = &stub_printfInSendToEmail;
  assert(get_call_printfInSendToEmail() == 0);
  print = printf;
}

static void TC_EvaluatePrintfParametersinsendToController(void)
{
  Reset_teststubs();
  print = &stub_printfInSendToController;  
  sendToController(TOO_LOW);
  assert(get_call_printfInSendToController()==1);
  assert(get_arg2_printfInSendToController()== 0xfeed );
  assert(get_arg3_printfInSendToController() == TOO_LOW);
  assert(strcmp(get_arg1_printfInSendToController(),"%x : %x\n")==0);
}


int main()
{
 TC_inferBreach_TOO_LOW(); 
 TC_inferBreach_TOO_HIGH(); 
 TC_inferBreach_NORMAL_equalsTOOLOW();
 TC_inferBreach_NORMAL_equalsTOOHIGH();
 TC_AlertcallinCheckandAlert();
 TC_Evaluate_BreachTypeToString_conversion();
 TC_EvaluatePrintfParametersinSendToEmail();
 TC_SendToEmail_duringNORMAL();
 TC_EvaluatePrintfParametersinsendToController();
 return 0;
}