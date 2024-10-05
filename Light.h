#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"

class Light : public SmartDevice {
private:
    bool isOn;
public:
    Light();
    std::string getStatus() const override;
    void performAction() override;
    std::string getDeviceType() const override;
};

#endif
