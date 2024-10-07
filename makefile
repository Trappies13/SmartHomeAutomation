CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

VALGRIND = valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all

EXEC = SmartHomeSystem
TEST_EXEC = runTests

SRC = Light.cpp Thermostat.cpp DoorLock.cpp TurnOffCommand.cpp MacroRoutine.cpp Sensor.cpp SmartThermostatIntegrator.cpp LegacyThermostat.cpp

TEST_SRC = UnitTestingMain.cpp

OBJ = $(SRC:.cpp=.o)

TEST_OBJ = $(TEST_SRC:.cpp=.o)

GTEST_LIBS = -lgtest -lgtest_main -pthread

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

$(TEST_EXEC): $(TEST_OBJ) $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(TEST_EXEC) $(TEST_OBJ) $(OBJ) $(GTEST_LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_EXEC)
	./$(TEST_EXEC)

memcheck: $(EXEC)
	$(VALGRIND) ./$(EXEC)

clean:
	rm -f $(OBJ) $(TEST_OBJ) $(EXEC) $(TEST_EXEC)

run: $(EXEC)
	./$(EXEC)

.PHONY: all test memcheck clean run
