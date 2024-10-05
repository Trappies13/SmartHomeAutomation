#include "Sensor.h"
#include <algorithm>

void Sensor::addDevice(SmartDevice* device) {
    devices.push_back(device);
}

void Sensor::removeDevice(SmartDevice* device) {
    auto it = std::find(devices.begin(), devices.end(), device);

    if (it != devices.end()) {
        devices.erase(it);
    }
}

void Sensor::notifyDevices() {
    for (SmartDevice* device : devices) {
        device->performAction();
    }
}
