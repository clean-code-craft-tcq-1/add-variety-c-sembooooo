#pragma once
#include "typewise-alert.h"

extern void AlertTestDouble(BreachType breach);
extern int GetCall_AlertTestDouble(void);
extern BreachType GetPar_breach(void);

extern int stub_printfInSendToEmail(const char *fmt , ...);
extern char* get_args_printfInSendToEmail(int index);
extern int get_call_printfInSendToEmail(void);

int stub_printfInSendToController(const char *fmt , ...);
extern char* get_arg1_printfInSendToController(void);
extern int get_arg2_printfInSendToController(void);
extern int get_arg3_printfInSendToController(void);
extern int get_call_printfInSendToController(void);

extern void Reset_teststubs(void);