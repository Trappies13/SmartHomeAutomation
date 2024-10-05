#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "SmartDevice.h"

class DoorLock : public SmartDevice {
private:
    bool isLocked;
public:
    DoorLock();
    std::string getStatus() const override;
    void performAction() override;
    std::string getDeviceType() const override;
};

#endif
