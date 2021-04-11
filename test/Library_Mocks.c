#include "Library_Mocks.h"
#include <string.h>

char toaddr[20];
char fromaddr[20];
char body[100];
int call_Email;

void Email(EmailContent_t Content)
{
    call_Email++;
    strcpy(toaddr,Content.toaddr);
    strcpy(fromaddr,Content.fromaddr);
    strcpy(body,Content.body);
}

char *GetToAddr(void)
{
    return toaddr;
}

char *GetFromAddr(void)
{
    return fromaddr;
}

char *GetBody(void)
{
    return body;
}

int GetCallCountToEmail(void)
{
    return call_Email;
}


int Par_deviceid;
int Par_Command;
int call_SPICommSendSignal;

void SPIComm_SendSignal(int Deviceid , int Command)
{
    Par_deviceid = Deviceid;
    Par_Command = Command;
    call_SPICommSendSignal++;
}

int GetDeviceID(void)
{
    return Par_deviceid;
}

int GetCommand(void)
{
    return Par_Command;
}

int GetCallCountToSPICommSendSignal(void)
{
    return call_SPICommSendSignal;
}


void Reset_LibraryMockVariables(void)
{  
    call_Email = call_SPICommSendSignal = Par_deviceid = Par_Command =0;
    memset(toaddr,0,20);
    memset(fromaddr,0,20);
    memset(body,0,100);
}

