#ifndef SENSOR_H
#define SENSOR_H

#include <vector>
#include "SmartDevice.h"

/**
 * @class Sensor
 * @brief A class that simulates a sensor in the smart home system.
 *
 * The Sensor class allows the registration of smart devices and notifies them 
 * when an environmental condition is met (e.g., motion detected).
 * It uses the observer pattern to notify registered devices.
 */
class Sensor {
private:
    std::vector<SmartDevice*> devices; ///< A list of devices registered to the sensor.
public:
    /**
     * @brief Adds a smart device to the sensor's list of devices to be notified.
     * @param device A pointer to the SmartDevice to be added.
     */
    void addDevice(SmartDevice* device);

    /**
     * @brief Removes a smart device from the sensor's list of devices.
     * @param device A pointer to the SmartDevice to be removed.
     */
    void removeDevice(SmartDevice* device);

    /**
     * @brief Notifies all registered devices when a condition is triggered.
     *
     * This method calls the performAction() method of all registered devices.
     */
    void notifyDevices();
};

#endif
