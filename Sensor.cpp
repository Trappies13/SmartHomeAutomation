#include "Sensor.h"
#include <algorithm>

/**
 * @brief Adds a smart device to the sensor's list of devices.
 * @param device A pointer to the SmartDevice to be added.
 */
void Sensor::addDevice(SmartDevice* device) {
    devices.push_back(device);
}

/**
 * @brief Removes a smart device from the sensor's list of devices.
 * @param device A pointer to the SmartDevice to be removed.
 *
 * This method finds the device in the list and removes it if found.
 */
void Sensor::removeDevice(SmartDevice* device) {
    auto it = std::find(devices.begin(), devices.end(), device);

    if (it != devices.end()) {
        devices.erase(it);
    }
}

/**
 * @brief Notifies all registered devices.
 *
 * This method calls the performAction() method on all devices that are currently registered with the sensor.
 */
void Sensor::notifyDevices() {
    for (SmartDevice* device : devices) {
        device->performAction();
    }
}
