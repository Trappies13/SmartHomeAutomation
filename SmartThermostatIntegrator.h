#ifndef SMARTTHERMOSTATINTEGRATOR_H
#define SMARTTHERMOSTATINTEGRATOR_H

#include "SmartDevice.h"
#include "LegacyThermostat.h"

class SmartThermostatIntegrator : public SmartDevice {
private:
    LegacyThermostat* legacyThermostat;
public:
    SmartThermostatIntegrator(LegacyThermostat* legacyDevice);
    std::string getStatus() const override;
    void performAction() override;
    std::string getDeviceType() const override;
    void setTemperature(int temp);
    int getTemperature() const;
};

#endif
