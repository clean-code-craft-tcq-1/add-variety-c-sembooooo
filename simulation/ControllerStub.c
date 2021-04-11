#include "../SoCalledControllerLibrary.h"
#include <stdio.h>

void SPIComm_SendSignal(int Deviceid , int Command)
{
    printf("Device Id : %d\n",Deviceid);
    printf("Command : %d\n",Command);
}