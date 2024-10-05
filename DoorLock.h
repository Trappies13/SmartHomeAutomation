#ifndef DOORLOCK_H
#define DOORLOCK_H

#include "SmartDevice.h"

/**
 * @class DoorLock
 * @brief A class that represents a smart door lock in the home automation system.
 *
 * The DoorLock class allows the user to lock or unlock a door and provides the status of the door lock.
 * It implements the SmartDevice interface.
 */
class DoorLock : public SmartDevice {
private:
    bool isLocked; ///< Indicates whether the door is locked or unlocked.
public:
    /**
     * @brief Constructor for the DoorLock class.
     *
     * Initializes the door lock to be unlocked by default.
     */
    DoorLock();

    /**
     * @brief Returns the current status of the door lock.
     * @return A string, either "locked" or "unlocked", representing the status of the door lock.
     */
    std::string getStatus() const override;

    /**
     * @brief Toggles the lock state of the door.
     *
     * Locks the door if it is unlocked, and unlocks the door if it is locked.
     */
    void performAction() override;

    /**
     * @brief Returns the type of device.
     * @return A string "DoorLock", representing the type of the device.
     */
    std::string getDeviceType() const override;
};

#endif
