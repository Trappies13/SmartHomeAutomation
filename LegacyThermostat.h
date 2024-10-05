#ifndef LEGACYTHERMOSTAT_H
#define LEGACYTHERMOSTAT_H

/**
 * @class LegacyThermostat
 * @brief A class that represents a legacy thermostat device.
 *
 * The LegacyThermostat class models an older thermostat device that does not have smart functionality.
 * It allows for setting and getting the temperature, but lacks the advanced features of a smart thermostat.
 */
class LegacyThermostat {
private:
    int temperature; ///< The current temperature of the thermostat.
public:
    /**
     * @brief Constructs a new LegacyThermostat object with an initial temperature.
     * @param initialTemp The initial temperature to set for the thermostat.
     */
    LegacyThermostat(int initialTemp);

    /**
     * @brief Returns the current temperature of the legacy thermostat.
     * @return An integer representing the current temperature.
     */
    int getLegacyTemperature() const;

    /**
     * @brief Sets the temperature for the legacy thermostat.
     * @param temp The new temperature to set for the thermostat.
     */
    void setLegacyTemperature(int temp);
};

#endif
