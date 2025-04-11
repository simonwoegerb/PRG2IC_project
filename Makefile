# Compiler
CXX := clang++

# Directories
SRC_DIR := src
OBJ_DIR := obj

# Compiler flags
CXXFLAGS := -Wall -Wextra -std=c++17 -O2 -I${SRC_DIR}/

# Debug flags (use `make debug` to enable them)
DEBUGFLAGS := -g -O0 -DDEBUG

# Source files (automatically find all .cpp files in src/)
SRC := $(wildcard $(SRC_DIR)/**/*.cpp $(SRC_DIR)/*.cpp)
# Object files (store .o files in obj/)
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

# Output executable
TARGET := lecture1

# Default rule
all: $(TARGET)

# Ensure obj directory and subdirectories exist
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	# Create the directory for the object file if it doesn't exist
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Link the final executable
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Debug build
.PHONY: debug
debug: CXXFLAGS += $(DEBUGFLAGS)
debug: clean all
# Debug run build and execute the program
.PHONY: debug_run
debug_run: debug
	./$(TARGET)

# Clean build files
.PHONY: clean
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Run the program
.PHONY: run
run: $(TARGET)
	./$(TARGET)
