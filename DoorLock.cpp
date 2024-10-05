#include "DoorLock.h"

/**
 * @brief Constructs a new DoorLock object.
 *
 * The door lock is initialized in the unlocked state.
 */
DoorLock::DoorLock() : isLocked(false) {}

/**
 * @brief Returns the current status of the door lock.
 * @return A string representing the current status: "locked" or "unlocked".
 */
std::string DoorLock::getStatus() const {
    return isLocked ? "locked" : "unlocked";
}

/**
 * @brief Toggles the lock state of the door.
 *
 * This method locks the door if it's unlocked, and unlocks it if it's locked.
 */
void DoorLock::performAction() {
    isLocked = !isLocked;
}

/**
 * @brief Returns the type of this device.
 * @return A string "DoorLock", representing the type of the device.
 */
std::string DoorLock::getDeviceType() const {
    return "DoorLock";
}
