CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC = src/main.cpp src/modular_math.cpp
OBJ = $(SRC:.cpp=.o)
INCLUDE = -Iinclude
TARGET = ecdh

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)