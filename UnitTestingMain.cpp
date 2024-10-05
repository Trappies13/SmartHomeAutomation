/**
 * @file test_main.cpp
 * @brief Unit tests for Smart Home Automation system components using Google Test framework.
 */

#include <gtest/gtest.h>
#include "Light.h"
#include "Thermostat.h"
#include "DoorLock.h"
#include "TurnOffCommand.h"
#include "SmartThermostatIntegrator.h"
#include "LegacyThermostat.h"
#include "MacroRoutine.h"
#include "Sensor.h"

/**
 * @brief Unit test for the Light class.
 * Tests the initial status of the light to ensure it is off.
 */
TEST(LightTest, InitialStatusIsOff) {
    Light light;
    EXPECT_EQ(light.getStatus(), "off");
}

/**
 * @brief Unit test for the Light class.
 * Tests toggling the light's state between on and off.
 */
TEST(LightTest, ToggleLight) {
    Light light;
    light.performAction(); // Turn the light on
    EXPECT_EQ(light.getStatus(), "on");
    light.performAction(); // Turn the light off
    EXPECT_EQ(light.getStatus(), "off");
}

/**
 * @brief Unit test for the Thermostat class.
 * Tests the initial temperature setting of the thermostat.
 */
TEST(ThermostatTest, InitialTemperature) {
    Thermostat thermostat(22);
    EXPECT_EQ(thermostat.getTemperature(), 22);
    EXPECT_EQ(thermostat.getStatus(), "Temperature: 22");
}

/**
 * @brief Unit test for the Thermostat class.
 * Tests increasing the thermostat temperature by 1 degree.
 */
TEST(ThermostatTest, IncreaseTemperature) {
    Thermostat thermostat(22);
    thermostat.performAction(); // Increase temperature by 1
    EXPECT_EQ(thermostat.getTemperature(), 23);
    EXPECT_EQ(thermostat.getStatus(), "Temperature: 23");
}

/**
 * @brief Unit test for the Thermostat class.
 * Tests manually setting the temperature of the thermostat.
 */
TEST(ThermostatTest, SetTemperature) {
    Thermostat thermostat(22);
    thermostat.setTemperature(25);
    EXPECT_EQ(thermostat.getTemperature(), 25);
    EXPECT_EQ(thermostat.getStatus(), "Temperature: 25");
}

/**
 * @brief Unit test for the Thermostat class.
 * Tests manually setting the temperature of the thermostat.
 */
TEST(DoorLockTest, InitialStatusIsUnlocked) {
    DoorLock door;
    EXPECT_EQ(door.getStatus(), "unlocked");
}

/**
 * @brief Unit test for the DoorLock class.
 * Tests toggling the door lock's state between locked and unlocked.
 */
TEST(DoorLockTest, ToggleLock) {
    DoorLock door;
    door.performAction(); // Lock the door
    EXPECT_EQ(door.getStatus(), "locked");
    door.performAction(); // Unlock the door
    EXPECT_EQ(door.getStatus(), "unlocked");
}

/**
 * @brief Unit test for the MacroRoutine class.
 * Tests adding and executing commands in a macro routine.
 */
TEST(MacroRoutineTest, AddAndExecuteCommands) {
    Light light;  // Ensure light is off initially
    DoorLock door;  // Ensure door is unlocked initially
    Command* turnOffLight = new TurnOffCommand(&light);
    Command* turnOffDoor = new TurnOffCommand(&door);

    MacroRoutine routine;

    // Turn the light on first
    light.performAction();
    EXPECT_EQ(light.getStatus(), "on");  // The light should now be on

    // Add procedures to the macro routine
    routine.addProcedure(turnOffLight);
    routine.addProcedure(turnOffDoor);

    // Before executing the routine
    EXPECT_EQ(door.getStatus(), "unlocked");  // Check door status

    // Execute the commands
    routine.execute();

    // Check the states after execution
    EXPECT_EQ(light.getStatus(), "off");  // The light should now be off
    EXPECT_EQ(door.getStatus(), "locked");  // The door should now be locked
}

/**
 * @brief Unit test for the Sensor class.
 * Tests adding devices to the sensor and notifying them.
 */
TEST(SensorTest, AddAndNotifyDevices) {
    Sensor sensor;
    Light light;
    DoorLock door;

    sensor.addDevice(&light);
    sensor.addDevice(&door);

    EXPECT_EQ(light.getStatus(), "off");
    EXPECT_EQ(door.getStatus(), "unlocked");

    sensor.notifyDevices();

    // Check the states after notifying (assuming the light gets turned on)
    EXPECT_EQ(light.getStatus(), "on");
    EXPECT_EQ(door.getStatus(), "locked"); // The door should be locked
}

/**
 * @brief Unit test for the LegacyThermostat class.
 * Tests setting and getting the legacy temperature.
 */
TEST(LegacyThermostatTest, SetAndGetLegacyTemperature) {
    LegacyThermostat legacyThermostat(20);
    EXPECT_EQ(legacyThermostat.getLegacyTemperature(), 20);

    legacyThermostat.setLegacyTemperature(25);
    EXPECT_EQ(legacyThermostat.getLegacyTemperature(), 25);
}

/**
 * @brief Unit test for the SmartThermostatIntegrator class.
 * Tests integration with a legacy thermostat.
 */
TEST(SmartThermostatIntegratorTest, IntegrateLegacyThermostat) {
    LegacyThermostat legacyThermostat(18);
    SmartThermostatIntegrator smartThermostat(&legacyThermostat);

    EXPECT_EQ(smartThermostat.getTemperature(), 18);
    EXPECT_EQ(smartThermostat.getStatus(), "Temperature: 18");

    smartThermostat.setTemperature(22);
    EXPECT_EQ(smartThermostat.getTemperature(), 22);
    EXPECT_EQ(smartThermostat.getStatus(), "Temperature: 22");
}

/**
 * @brief Unit test for the TurnOffCommand class.
 * Tests executing the TurnOffCommand on a light.
 */
TEST(TurnOffCommandTest, ExecuteTurnOffCommand) {
    Light light;
    TurnOffCommand turnOffCommand(&light);
    
    light.performAction(); // Turn the light on
    EXPECT_EQ(light.getStatus(), "on");
    
    turnOffCommand.execute(); // Execute the command to turn off the light
    EXPECT_EQ(light.getStatus(), "off");
}

/**
 * @brief Main function to run all unit tests.
 * Initializes the Google Test framework and runs all test cases.
 * @param argc Argument count
 * @param argv Argument vector
 * @return Returns 0 if all tests pass, otherwise non-zero.
 */
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
