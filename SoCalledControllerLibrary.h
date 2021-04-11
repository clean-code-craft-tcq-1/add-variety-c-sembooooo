#pragma once

#define DEVICEID_FAN_ASIC             0X01
#define DEVICEID_MOTOR_ASIC           0X02




extern void SPIComm_SendSignal(int DeviceID , int Command);
