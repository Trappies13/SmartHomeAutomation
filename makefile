# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

# Valgrind command
VALGRIND = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all

# Executable name for the main program and tests
EXEC = SmartHomeSystem
TEST_EXEC = runTests

# Source files for the main application
SRC = Light.cpp Thermostat.cpp DoorLock.cpp TurnOffCommand.cpp MacroRoutine.cpp Sensor.cpp SmartThermostatIntegrator.cpp LegacyThermostat.cpp

# Test source files
TEST_SRC = UnitTestingMain.cpp

# Object files (replace .cpp with .o)
OBJ = $(SRC:.cpp=.o)

# Test object files
TEST_OBJ = $(TEST_SRC:.cpp=.o)

# GTest flags
GTEST_LIBS = -lgtest -lgtest_main -pthread

# Default rule: Build the main program
all: $(EXEC)

# Rule to link the object files to create the main executable
$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

# Rule to build the test executable with Google Test
$(TEST_EXEC): $(TEST_OBJ) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) $(OBJ) $(GTEST_LIBS)

# Rule to compile the .cpp files into .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run unit tests
test: $(TEST_EXEC)
	./$(TEST_EXEC)

# Memory check using Valgrind
memcheck: $(EXEC)
	$(VALGRIND) ./$(EXEC)

# Clean up object files and executables
clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) $(TEST_EXEC)

# Run the main program
run: $(EXEC)
	./$(EXEC)

# Phony targets
.PHONY: all test memcheck clean run
