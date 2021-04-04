#pragma once
#include "typewise-alert.h"

void AlertTestDouble(BreachType breach);
int GetCall_AlertTestDouble(void);
BreachType GetPar_breach(void);

extern int stub_printfInSendToEmail(const char *restrict , ...);
extern char* get_args_printfInSendToEmail(int index);
extern int get_call_printfInSendToEmail(void);