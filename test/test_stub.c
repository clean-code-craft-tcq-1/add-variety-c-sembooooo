#include "test_stub.h"
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

int GetCall_AlertTestDouble(void)
{
  int ret= Call_AlertTestDouble;
  Call_AlertTestDouble = 0;
  return ret;
}

BreachType GetPar_breach(void)
{
  BreachType ret = par_breach;
  par_breach = NORMAL;
  return ret; 
}



/**
 * The below function is a testcode to capture the parameters passed to printf.
 * As of today , only two strings are passed as parameters to the printf hence 
 * global varaible args_printfInSendToEmail is a multidimensional array.
 * 
 * The variable args_printfInSendToEmail  needs to be changed if number of 
 * parameters passed to printf in SendToEmail() changes.
 * 
 */ 
char args_printfInSendToEmail[2][30];
int call_printfInSendToEmail;

int stub_printfInSendToEmail(const char *fmt , ...)
{
  char *arg;
  va_list arg_list;
  va_start(arg_list,fmt);
  arg = va_arg(arg_list, char *);
  strcpy(args_printfInSendToEmail[0],arg);
  arg = va_arg(arg_list, char *);
  strcpy(args_printfInSendToEmail[1],arg);
  call_printfInSendToEmail++;
  return 1;
}

char* get_args_printfInSendToEmail(int index)
{
  return args_printfInSendToEmail[index];
}

int get_call_printfInSendToEmail(void)
{
  int ret =call_printfInSendToEmail;
  call_printfInSendToEmail = 0;
  return ret;
}

