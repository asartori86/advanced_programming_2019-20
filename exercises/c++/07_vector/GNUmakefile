SRC = as_vector.cc

CXX = c++
CXXFLAGS = -Wall -Wextra -std=c++14 -I ../../../lectures/c++/06_error_handling/

EXE = $(SRC:.cc=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cc .x

all: $(EXE)

.PHONY: all

%.x: %.cc 
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this command"

.PHONY: format

clean:
	rm -f $(EXE) *~

.PHONY: clean

01_surprise.x: CXXFLAGS += -Wno-uninitialized
