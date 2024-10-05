#ifndef LIGHT_H
#define LIGHT_H

#include "SmartDevice.h"

/**
 * @class Light
 * @brief A class that represents a smart light in the home automation system.
 *
 * The Light class allows the user to turn the light on or off and provides the current status of the light.
 * It implements the SmartDevice interface.
 */
class Light : public SmartDevice {
private:
    bool isOn; ///< Indicates whether the light is on or off.
public:
    /**
     * @brief Constructs a new Light object.
     *
     * Initializes the light to the off state.
     */
    Light();

    /**
     * @brief Returns the current status of the light.
     * @return A string, either "on" or "off", representing the light's status.
     */
    std::string getStatus() const override;

    /**
     * @brief Toggles the light's state between on and off.
     *
     * Changes the light's state from off to on, or from on to off.
     */
    void performAction() override;

    /**
     * @brief Returns the type of the device.
     * @return A string "Light", representing the type of the device.
     */
    std::string getDeviceType() const override;
};

#endif
