#include "SmartThermostatIntegrator.h"
#include <string>

SmartThermostatIntegrator::SmartThermostatIntegrator(LegacyThermostat* legacyDevice) 
    : legacyThermostat(legacyDevice) {}

std::string SmartThermostatIntegrator::getStatus() const {
    return "Temperature: " + std::to_string(legacyThermostat->getLegacyTemperature());
}

void SmartThermostatIntegrator::performAction() {
    legacyThermostat->setLegacyTemperature(legacyThermostat->getLegacyTemperature() + 1);
}

std::string SmartThermostatIntegrator::getDeviceType() const {
    return "SmartThermostat";
}

void SmartThermostatIntegrator::setTemperature(int temp) {
    legacyThermostat->setLegacyTemperature(temp);
}

int SmartThermostatIntegrator::getTemperature() const {
    return legacyThermostat->getLegacyTemperature();
}
