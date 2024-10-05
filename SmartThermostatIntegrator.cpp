#include "SmartThermostatIntegrator.h"
#include <string>

/**
 * @brief Constructs a SmartThermostatIntegrator object with the given legacy thermostat.
 * @param legacyDevice A pointer to the legacy thermostat being adapted.
 */
SmartThermostatIntegrator::SmartThermostatIntegrator(LegacyThermostat* legacyDevice) 
    : legacyThermostat(legacyDevice) {}

/**
 * @brief Returns the current temperature of the legacy thermostat.
 * @return A string representing the temperature in the format "Temperature: X".
 */
std::string SmartThermostatIntegrator::getStatus() const {
    return "Temperature: " + std::to_string(legacyThermostat->getLegacyTemperature());
}

/**
 * @brief Increases the temperature of the thermostat by 1 degree.
 */
void SmartThermostatIntegrator::performAction() {
    legacyThermostat->setLegacyTemperature(legacyThermostat->getLegacyTemperature() + 1);
}

/**
 * @brief Returns the type of the device.
 * @return A string "SmartThermostat", representing the type of the device.
 */
std::string SmartThermostatIntegrator::getDeviceType() const {
    return "SmartThermostat";
}

/**
 * @brief Sets the temperature of the legacy thermostat.
 * @param temp The new temperature to set.
 */
void SmartThermostatIntegrator::setTemperature(int temp) {
    legacyThermostat->setLegacyTemperature(temp);
}

/**
 * @brief Gets the current temperature of the legacy thermostat.
 * @return The current temperature of the thermostat.
 */
int SmartThermostatIntegrator::getTemperature() const {
    return legacyThermostat->getLegacyTemperature();
}
