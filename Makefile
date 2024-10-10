# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g

WORKDIR = app
# Source files
SRCS = $(WORKDIR)/Main.cpp $(WORKDIR)/Game.cpp $(WORKDIR)/NonBlockingInput.cpp $(WORKDIR)/Snake.cpp $(WORKDIR)/Food.cpp

# Target executable
TARGET = SnakeGame

# Default rule to build the program
all: $(TARGET)

# Rule to compile and link all .cpp files into one executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Rule to clean the build
clean:
	rm -f $(TARGET)

# Rule to compile and run the program automatically
auto: $(TARGET)
	./$(TARGET)
