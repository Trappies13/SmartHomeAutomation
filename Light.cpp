#include "Light.h"

/**
 * @brief Constructs a new Light object.
 *
 * Initializes the light to the off state.
 */
Light::Light() : isOn(false) {}

/**
 * @brief Returns the current status of the light.
 * @return A string representing the current status: "on" or "off".
 */
std::string Light::getStatus() const {
    return isOn ? "on" : "off";
}

/**
 * @brief Toggles the light's state between on and off.
 *
 * This method switches the light on if it's off, and switches it off if it's on.
 */
void Light::performAction() {
    isOn = !isOn;
}

/**
 * @brief Returns the type of this device.
 * @return A string "Light", representing the type of the device.
 */
std::string Light::getDeviceType() const {
    return "Light";
}
