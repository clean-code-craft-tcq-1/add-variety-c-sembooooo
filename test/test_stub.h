#pragma once
#include "typewise-alert.h"

extern void AlertTestDouble(BreachType breach);
extern int GetCall_AlertTestDouble(void);
extern BreachType GetPar_breach(void);

extern int stub_printfInSendToEmail(const char *restrict , ...);
extern char* get_args_printfInSendToEmail(int index);
extern int get_call_printfInSendToEmail(void);