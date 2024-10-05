#ifndef SMARTTHERMOSTATINTEGRATOR_H
#define SMARTTHERMOSTATINTEGRATOR_H

#include "SmartDevice.h"
#include "LegacyThermostat.h"

/**
 * @class SmartThermostatIntegrator
 * @brief An adapter class that integrates a legacy thermostat into the smart home system.
 *
 * The SmartThermostatIntegrator class adapts the interface of a LegacyThermostat 
 * to make it compatible with the SmartDevice interface. This allows an old thermostat 
 * to be controlled like any other smart device in the system.
 */
class SmartThermostatIntegrator : public SmartDevice {
private:
    LegacyThermostat* legacyThermostat; ///< A pointer to the legacy thermostat being adapted.
public:
    /**
     * @brief Constructs a SmartThermostatIntegrator with a pointer to the legacy thermostat.
     * @param legacyDevice A pointer to the LegacyThermostat that will be adapted.
     */
    SmartThermostatIntegrator(LegacyThermostat* legacyDevice);

    /**
     * @brief Returns the current temperature of the legacy thermostat.
     * @return A string showing the temperature in the format "Temperature: X".
     */
    std::string getStatus() const override;

    /**
     * @brief Increases the temperature by 1 degree.
     */
    void performAction() override;

    /**
     * @brief Gets the type of the device.
     * @return A string "SmartThermostat", representing the type of the device.
     */
    std::string getDeviceType() const override;

    /**
     * @brief Sets the temperature of the thermostat.
     * @param temp The new temperature to set on the legacy thermostat.
     */
    void setTemperature(int temp);

    /**
     * @brief Gets the current temperature of the thermostat.
     * @return The current temperature of the legacy thermostat.
     */
    int getTemperature() const;
};

#endif
