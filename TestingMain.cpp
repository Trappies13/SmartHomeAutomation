// #include <iostream>
// #include "Light.h"
// #include "Thermostat.h"
// #include "DoorLock.h"
// #include "TurnOffCommand.h"
// #include "SmartThermostatIntegrator.h"
// #include "LegacyThermostat.h"
// #include "MacroRoutine.h"
// #include "Sensor.h"

// /**
//  * @brief The main function of the Smart Home Automation System.
//  *
//  * This function demonstrates the use of smart devices such as lights, thermostats, and door locks,
//  * along with command patterns, sensor notifications, and the adapter pattern for legacy devices.
//  * It initializes the devices, executes various commands, and simulates sensor-triggered actions.
//  *
//  * @return 0 if the program runs successfully.
//  */
// int main() {
//     // Create smart devices
//     Light livingRoomLight; ///< Represents a smart light in the living room.
//     DoorLock frontDoorLock; ///< Represents a smart door lock for the front door.
//     Thermostat kitchenThermostat(22); ///< Represents a smart thermostat in the kitchen with an initial temperature of 22°C.

//     // Display the initial statuses of the devices
//     std::cout << "Initial device statuses:\n";
//     std::cout << "Living Room Light: " << livingRoomLight.getStatus() << "\n";
//     std::cout << "Front Door Lock: " << frontDoorLock.getStatus() << "\n";
//     std::cout << "Kitchen Thermostat: " << kitchenThermostat.getStatus() << "\n";

//     // Execute a TurnOffCommand on the living room light
//     std::cout << "\n--- Executing TurnOffCommand on Living Room Light ---\n";
//     Command* turnOffLight = new TurnOffCommand(&livingRoomLight); ///< Creates a TurnOffCommand to toggle the light.
//     turnOffLight->execute(); ///< Executes the command, turning the light off.
//     std::cout << "Living Room Light status: " << livingRoomLight.getStatus() << "\n";

//     // Create a MacroRoutine (Goodnight Routine) to turn off all devices
//     std::cout << "\n--- Creating MacroRoutine: Goodnight Routine ---\n";
//     Command* turnOffFrontDoorLock = new TurnOffCommand(&frontDoorLock); ///< Command to lock the front door.
//     Command* turnOffLivingRoomLight = new TurnOffCommand(&livingRoomLight); ///< Command to turn off the living room light.

//     MacroRoutine goodnightRoutine; ///< A macro routine to perform multiple actions.
//     goodnightRoutine.addProcedure(turnOffFrontDoorLock); ///< Adds the front door lock command to the routine.
//     goodnightRoutine.addProcedure(turnOffLivingRoomLight); ///< Adds the living room light command to the routine.

//     std::cout << "Executing Goodnight Routine:\n";
//     goodnightRoutine.execute(); ///< Executes the macro routine.
//     std::cout << "Living Room Light status: " << livingRoomLight.getStatus() << "\n";
//     std::cout << "Front Door Lock status: " << frontDoorLock.getStatus() << "\n";

//     // Adapting a LegacyThermostat into the system using the Adapter Pattern
//     std::cout << "\n--- Adapting Legacy Thermostat into the Smart Home System ---\n";
//     LegacyThermostat oldThermostat(18); ///< A legacy thermostat with an initial temperature of 18°C.
//     SmartThermostatIntegrator smartThermostat(&oldThermostat); ///< Adapts the legacy thermostat into a smart thermostat.

//     std::cout << "Legacy Thermostat temperature (via adapter): " << smartThermostat.getStatus() << "\n";
//     smartThermostat.setTemperature(24); ///< Sets a new temperature for the legacy thermostat via the adapter.
//     std::cout << "New Legacy Thermostat temperature (via adapter): " << smartThermostat.getStatus() << "\n";

//     // Simulating sensor-triggered actions (e.g., detecting motion and notifying devices)
//     std::cout << "\n--- Sensor detects movement and notifies connected devices ---\n";
//     Sensor motionSensor; ///< A sensor that detects movement and triggers actions.

//     motionSensor.addDevice(&livingRoomLight); ///< Adds the living room light to the sensor's device list.
//     motionSensor.addDevice(&frontDoorLock); ///< Adds the front door lock to the sensor's device list.

//     std::cout << "Before sensor notification:\n";
//     std::cout << "Living Room Light status: " << livingRoomLight.getStatus() << "\n";
//     std::cout << "Front Door Lock status: " << frontDoorLock.getStatus() << "\n";

//     motionSensor.notifyDevices(); ///< The sensor detects movement and notifies the devices to take action.

//     std::cout << "After sensor notification:\n";
//     std::cout << "Living Room Light status: " << livingRoomLight.getStatus() << "\n";
//     std::cout << "Front Door Lock status: " << frontDoorLock.getStatus() << "\n";

//     // Clean up dynamically allocated memory
//     delete turnOffLight;

//     return 0;
// }
