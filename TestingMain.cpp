#include <iostream>
#include "Light.h"
#include "Thermostat.h"
#include "DoorLock.h"
#include "TurnOffCommand.h"
#include "SmartThermostatIntegrator.h"
#include "LegacyThermostat.h"
#include "MacroRoutine.h"
#include "Sensor.h"

int main() {
    Light livingRoomLight;
    DoorLock frontDoorLock;
    Thermostat kitchenThermostat(22);

    std::cout << "Initial device statuses:\n";
    std::cout << "Living Room Light: " << livingRoomLight.getStatus() << "\n";
    std::cout << "Front Door Lock: " << frontDoorLock.getStatus() << "\n";
    std::cout << "Kitchen Thermostat: " << kitchenThermostat.getStatus() << "\n";

    std::cout << "\n--- Executing TurnOffCommand on Living Room Light ---\n";
    Command* turnOffLight = new TurnOffCommand(&livingRoomLight);
    turnOffLight->execute();
    std::cout << "Living Room Light status: " << livingRoomLight.getStatus() << "\n";

    std::cout << "\n--- Creating MacroRoutine: Goodnight Routine ---\n";
    Command* turnOffFrontDoorLock = new TurnOffCommand(&frontDoorLock);
    Command* turnOffLivingRoomLight = new TurnOffCommand(&livingRoomLight);

    MacroRoutine goodnightRoutine;
    goodnightRoutine.addProcedure(turnOffFrontDoorLock);
    goodnightRoutine.addProcedure(turnOffLivingRoomLight);

    std::cout << "Executing Goodnight Routine:\n";
    goodnightRoutine.execute();
    std::cout << "Living Room Light status: " << livingRoomLight.getStatus() << "\n";
    std::cout << "Front Door Lock status: " << frontDoorLock.getStatus() << "\n";

    std::cout << "\n--- Adapting Legacy Thermostat into the Smart Home System ---\n";
    LegacyThermostat oldThermostat(18);
    SmartThermostatIntegrator smartThermostat(&oldThermostat);

    std::cout << "Legacy Thermostat temperature (via adapter): " << smartThermostat.getStatus() << "\n";

    smartThermostat.setTemperature(24);
    std::cout << "New Legacy Thermostat temperature (via adapter): " << smartThermostat.getStatus() << "\n";

    std::cout << "\n--- Sensor detects movement and notifies connected devices ---\n";
    Sensor motionSensor;

    motionSensor.addDevice(&livingRoomLight);
    motionSensor.addDevice(&frontDoorLock);

    std::cout << "Before sensor notification:\n";
    std::cout << "Living Room Light status: " << livingRoomLight.getStatus() << "\n";
    std::cout << "Front Door Lock status: " << frontDoorLock.getStatus() << "\n";

    motionSensor.notifyDevices();

    std::cout << "After sensor notification:\n";
    std::cout << "Living Room Light status: " << livingRoomLight.getStatus() << "\n";
    std::cout << "Front Door Lock status: " << frontDoorLock.getStatus() << "\n";

    delete turnOffLight;

    return 0;
}
