#include "test_stub.h"
#include "typewise-alert.c"
#include <string.h>


int TestCase_isArg1toPrintfinSendToEmailCorrect(void)
{
  print = &stub_printfInSendToEmail;
  sendToEmail(TOO_LOW);
  return !(strcmp(get_args_printfInSendToEmail(0),"a.b@c.com"));
}

int TestCase_isArg2toPrintfinSendToEmailCorrect(void)
{
  print = &stub_printfInSendToEmail;
  sendToEmail(TOO_LOW);
  return !(strcmp(get_args_printfInSendToEmail(0),"a.b@c.com"));
}


