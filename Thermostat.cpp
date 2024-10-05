#include "Thermostat.h"

/**
 * @brief Constructs a new Thermostat object with the specified initial temperature.
 * @param initialTemp The initial temperature to set for the thermostat.
 */
Thermostat::Thermostat(int initialTemp) : temperature(initialTemp) {}

/**
 * @brief Returns the current temperature of the thermostat.
 * @return A string representing the temperature in the format "Temperature: X".
 */
std::string Thermostat::getStatus() const {
    return "Temperature: " + std::to_string(temperature);
}

/**
 * @brief Increases the temperature by 1 degree.
 */
void Thermostat::performAction() {
    temperature += 1;
}

/**
 * @brief Returns the type of the device.
 * @return A string "Thermostat", representing the type of the device.
 */
std::string Thermostat::getDeviceType() const {
    return "Thermostat";
}

/**
 * @brief Sets the temperature of the thermostat.
 * @param temp The new temperature to set for the thermostat.
 */
void Thermostat::setTemperature(int temp) {
    temperature = temp;
}

/**
 * @brief Gets the current temperature of the thermostat.
 * @return The current temperature of the thermostat.
 */
int Thermostat::getTemperature() const {
    return temperature;
}
