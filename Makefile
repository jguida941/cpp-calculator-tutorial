# Makefile for C++ Calculator Project
# Educational project for learning C++ basics

# Compiler settings
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
DEBUG_FLAGS = -g -O0
RELEASE_FLAGS = -O2

# Directories
SRC_DIR = src
BUILD_DIR = build

# Files
TARGET = $(BUILD_DIR)/calculator
SOURCE = $(SRC_DIR)/calculator.cpp

# Default target
all: $(TARGET)

# Build the calculator
$(TARGET): $(SOURCE) | $(BUILD_DIR)
	@echo "Building calculator..."
	$(CXX) $(CXXFLAGS) $(RELEASE_FLAGS) -o $(TARGET) $(SOURCE)
	@echo "Build complete! Run with: ./$(TARGET)"

# Debug build
debug: $(SOURCE) | $(BUILD_DIR)
	@echo "Building calculator with debug symbols..."
	$(CXX) $(CXXFLAGS) $(DEBUG_FLAGS) -o $(TARGET) $(SOURCE)
	@echo "Debug build complete!"

# Create build directory if it doesn't exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Run the calculator
run: $(TARGET)
	@echo "Starting calculator..."
	@./$(TARGET)

# Clean build files
clean:
	@echo "Cleaning build files..."
	@rm -rf $(BUILD_DIR)
	@echo "Clean complete!"

# Rebuild from scratch
rebuild: clean all

# Help target
help:
	@echo "Available targets:"
	@echo "  make         - Build the calculator"
	@echo "  make debug   - Build with debug symbols"
	@echo "  make run     - Build and run the calculator"
	@echo "  make clean   - Remove build files"
	@echo "  make rebuild - Clean and rebuild"
	@echo "  make help    - Show this help message"

.PHONY: all debug run clean rebuild help