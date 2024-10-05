#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

class Thermostat : public SmartDevice {
private:
    int temperature;
public:
    Thermostat(int initialTemp);
    std::string getStatus() const override;
    void performAction() override;
    std::string getDeviceType() const override;
    void setTemperature(int temp);
    int getTemperature() const;
};

#endif
