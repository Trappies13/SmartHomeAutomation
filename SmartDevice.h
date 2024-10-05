#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

class SmartDevice {
public:
    virtual std::string getStatus() const = 0;
    virtual void performAction() = 0;
    virtual std::string getDeviceType() const = 0;
    virtual ~SmartDevice() = default;
};

#endif
