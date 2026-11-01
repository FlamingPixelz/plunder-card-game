CXX      := g++
CXXFLAGS := -std=c++17 -Wall
SRC      := $(wildcard Plunder/*.cpp)
HEADERS  := $(wildcard Plunder/*.h)
TARGET   := plunder

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: run clean