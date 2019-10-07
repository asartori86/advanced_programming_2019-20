SRC = 01_functions.cc         \
      02_overloading.cc	      \
      03_templates.cc         \
      04_wrong_args.cc        \
      05_swaps.cc             \
      06_static_arrays.cc     \
      07_dynamic_arrays.cc

CXX = c++
CXXFLAGS = -Wall -Wextra -g -std=c++14

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
