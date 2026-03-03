CXXFLAGS += -I.
CXXFLAGS += -std=c++2a
CXXFLAGS += -Wall
CXXFLAGS += -Wextra
CXXFLAGS += -Wshadow
CXXFLAGS += -Wfloat-equal
CXXFLAGS += -O
CXXFLAGS += -Wsequence-point
CXXFLAGS += -Wmissing-noreturn
CXXFLAGS += -Wunreachable-code

CXXFLAGS += -fprofile-arcs -ftest-coverage

CXXFLAGS += -fsanitize=leak,address
CXXFLAGS += -fno-sanitize-recover=undefined
CXXFLAGS += -fno-omit-frame-pointer

CXXFLAGS += -include-pch /usr/local/include/gtest/gtest.h.pch
CXXFLAGS += -include-pch /usr/local/include/gmock/gmock.h.pch

GTEST_LIBS = -lgtest -lgmock -lgmock_main -pthread

HPP_FILES = $(wildcard *.hpp)
CPP_FILES = $(wildcard *.cpp)

.PHONY: test.output
test.output: test makefile
	@./$< --gtest_shuffle

test: $(CPP_FILES) $(HPP_FILES)
	@$(CXX) $(CXXFLAGS) -O $(CPP_FILES) $(GTEST_LIBS) -o $@
