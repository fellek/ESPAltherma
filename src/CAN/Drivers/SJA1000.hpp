#ifndef DRIVER_SJA1000_H
#define DRIVER_SJA1000_H

#include "driver/twai.h"
#include "CAN/CANDriver.hpp"
#include "Config/config.hpp"
#include "debugSerial.hpp"

class DriverSJA1000 : public CANDriver
{
private:
  twai_general_config_t g_config;
  twai_filter_config_t f_config;
  twai_timing_config_t t_config;
  bool driverIsRunning;

  bool setMode(CanDriverMode mode);
  bool getRate(const uint16_t speed, twai_timing_config_t &t_config);

public:
  bool initInterface();
  void writeLoopbackTest();
  void sendCommand(CommandDef* cmd, bool setValue = false, int value = 0);
   void handleLoop();
};

#endif