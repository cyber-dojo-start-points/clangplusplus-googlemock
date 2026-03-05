CXXFLAGS += -I.
CXXFLAGS += -std=c++20
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Wshadow
CXXFLAGS += -Wfloat-equal
CXXFLAGS += -O0
CXXFLAGS += -Wsequence-point
CXXFLAGS += -Wmissing-noreturn
CXXFLAGS += -Wunreachable-code

CXXFLAGS += -fprofile-arcs -ftest-coverage

CXXFLAGS += -fsanitize=leak,address
CXXFLAGS += -fno-sanitize-recover=undefined
CXXFLAGS += -fno-omit-frame-pointer
CXXFLAGS += -pthread

# Works only if the above compilation flags are NOT changed
# Remove otherwise.
CXXFLAGS += -include-pch /usr/local/include/gtest/gtest.h.pch
CXXFLAGS += -include-pch /usr/local/include/gmock/gmock.h.pch

GTEST_LIBS = -lgtest -lgmock -lgmock_main

HPP_FILES = $(wildcard *.hpp)
CPP_FILES = $(wildcard *.cpp)
OBJ_FILES = $(CPP_FILES:.cpp=.o)

.PHONY: test.output
test.output: test makefile
	@./$< --gtest_shuffle

test: $(OBJ_FILES)
	@$(CXX) $(CXXFLAGS) $^ $(GTEST_LIBS) -o $@

%.o: %.cpp $(HPP_FILES) makefile
	@$(CXX) $(CXXFLAGS) -c $< -o $@
