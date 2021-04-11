#pragma once

#include "../SoCalledControllerLibrary.h"
#include "../SoCalledEmailLibrary.h"

extern char *GetToAddr(void);
extern char *GetFromAddr(void);
extern char *GetBody(void);


extern int GetDeviceID(void);
extern int GetCommand(void);
extern int GetCallCountToSPICommSendSignal(void);

extern void Reset_LibraryMockVariables(void);