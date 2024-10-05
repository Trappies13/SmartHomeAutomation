#include "LegacyThermostat.h"

/**
 * @brief Constructs a new LegacyThermostat object with the specified initial temperature.
 * @param initialTemp The initial temperature to set for the thermostat.
 */
LegacyThermostat::LegacyThermostat(int initialTemp) : temperature(initialTemp) {}

/**
 * @brief Returns the current temperature of the legacy thermostat.
 * @return An integer representing the current temperature.
 */
int LegacyThermostat::getLegacyTemperature() const {
    return temperature;
}

/**
 * @brief Sets the temperature for the legacy thermostat.
 * @param temp The new temperature to set for the thermostat.
 */
void LegacyThermostat::setLegacyTemperature(int temp) {
    temperature = temp;
}
