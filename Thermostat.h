#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "SmartDevice.h"

/**
 * @class Thermostat
 * @brief A class that represents a smart thermostat in the home automation system.
 *
 * The Thermostat class allows the user to set and adjust the temperature, as well as query its current temperature.
 * It implements the SmartDevice interface.
 */
class Thermostat : public SmartDevice {
private:
    int temperature; ///< The current temperature of the thermostat.
public:
    /**
     * @brief Constructs a new Thermostat object with an initial temperature.
     * @param initialTemp The initial temperature to set for the thermostat.
     */
    Thermostat(int initialTemp);

    /**
     * @brief Returns the current temperature of the thermostat.
     * @return A string representing the temperature in the format "Temperature: X".
     */
    std::string getStatus() const override;

    /**
     * @brief Increases the temperature by 1 degree.
     */
    void performAction() override;

    /**
     * @brief Returns the type of the device.
     * @return A string "Thermostat", representing the type of the device.
     */
    std::string getDeviceType() const override;

    /**
     * @brief Sets the temperature of the thermostat.
     * @param temp The new temperature to set for the thermostat.
     */
    void setTemperature(int temp);

    /**
     * @brief Gets the current temperature of the thermostat.
     * @return The current temperature of the thermostat.
     */
    int getTemperature() const;
};

#endif
