#include "Thermostat.h"

Thermostat::Thermostat(int initialTemp) : temperature(initialTemp) {}

std::string Thermostat::getStatus() const {
    return "Temperature: " + std::to_string(temperature);
}

void Thermostat::performAction() {
    temperature += 1;
}

std::string Thermostat::getDeviceType() const {
    return "Thermostat";
}

void Thermostat::setTemperature(int temp) {
    temperature = temp;
}

int Thermostat::getTemperature() const {
    return temperature;
}
