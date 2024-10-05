#ifndef SMARTDEVICE_H
#define SMARTDEVICE_H

#include <string>

/**
 * @class SmartDevice
 * @brief An abstract base class representing a smart device in the home automation system.
 *
 * The SmartDevice class provides an interface for devices like lights, thermostats, and locks. 
 * It includes methods for querying the device status, performing an action, and getting the device type.
 */
class SmartDevice {
public:
    /**
     * @brief Gets the current status of the smart device.
     * @return A string representing the device's status (e.g., "on", "off", "locked", etc.).
     */
    virtual std::string getStatus() const = 0;

    /**
     * @brief Performs the device's main action (e.g., toggling the light, locking/unlocking a door).
     */
    virtual void performAction() = 0;

    /**
     * @brief Gets the type of the device.
     * @return A string representing the type of the device (e.g., "Light", "DoorLock").
     */
    virtual std::string getDeviceType() const = 0;

    /**
     * @brief Virtual destructor to ensure proper cleanup of derived objects.
     */
    virtual ~SmartDevice() = default;
};

#endif
