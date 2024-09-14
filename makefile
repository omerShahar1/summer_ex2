#omer shahar
#207689621
#omerzshahar@gmail.com

CXX = g++
CXXFLAGS = -std=c++11 -Wall -fPIC `pkg-config --cflags Qt5Widgets`
LDFLAGS = `pkg-config --libs Qt5Widgets`
TARGET = tree_demo
TEST_TARGET = test_demo

# Source files
SRCS = main.cpp tree.hpp node.hpp Complex.hpp
TEST_SRCS = test.cpp tree.hpp node.hpp Complex.hpp

# Object files
OBJS = main.o
TEST_OBJS = test.o

# Default target: Build the executables
all: $(TARGET) $(TEST_TARGET)

# Build the main executable from object files
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Build the test executable from object files
$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_OBJS) $(LDFLAGS)

# Compile source files into object files
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c test.cpp -o test.o

# Clean up generated files
clean:
	rm -f $(OBJS) $(TEST_OBJS) $(TARGET) $(TEST_TARGET)

# Run the demo
run: $(TARGET)
	./$(TARGET)

# Run the tests
test: $(TEST_TARGET)
	./$(TEST_TARGET)
