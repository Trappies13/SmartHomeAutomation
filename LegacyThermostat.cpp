#include "LegacyThermostat.h"

LegacyThermostat::LegacyThermostat(int initialTemp) : temperature(initialTemp) {}

int LegacyThermostat::getLegacyTemperature() const {
    return temperature;
}

void LegacyThermostat::setLegacyTemperature(int temp) {
    temperature = temp;
}
