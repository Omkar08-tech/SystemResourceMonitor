CXX = g++
CXXFLAGS = -std=c++17 -Wall -lncurses

SRC = src/main.cpp src/cpu.cpp src/memory.cpp src/process.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = sysmon

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $@ $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)