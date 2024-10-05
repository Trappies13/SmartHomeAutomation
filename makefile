# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Executable name
EXEC = SmartHomeSystem

# Source files
SRC = TestingMain.cpp Light.cpp DoorLock.cpp Thermostat.cpp TurnOffCommand.cpp MacroRoutine.cpp Sensor.cpp LegacyThermostat.cpp SmartThermostatIntegrator.cpp

# Object files (replace .cpp with .o)
OBJ = $(SRC:.cpp=.o)

# Default rule: Build the program
all: $(EXEC)

# Rule to link the object files to create the executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Rule to compile the .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and the executable
clean:
	rm -f $(OBJ) $(EXEC)

# Run the program
run: $(EXEC)
	./$(EXEC)
