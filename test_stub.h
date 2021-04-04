#include "typewise-alert.h"

void AlertTestDouble(BreachType breach);
int GetCall_AlertTestDouble(void);
BreachType GetPar_breach(void);

int stub_printfInSendToEmail(const char *restrict , ...);
char* get_args_printfInSendToEmail(int index);
int get_call_printfInSendToEmail(void);