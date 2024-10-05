#include "Light.h"

Light::Light() : isOn(false) {}

std::string Light::getStatus() const {
    return isOn ? "on" : "off";
}

void Light::performAction() {
    isOn = !isOn;
}

std::string Light::getDeviceType() const {
    return "Light";
}
