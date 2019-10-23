SRC = 01_surprise.cc      \
      02_default.cc       \
      03_default.cc       \
      04_buggy_vector.cc  \
      05_buggy_vector.cc  \
      06_copy_move.cc     

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

01_surprise.x: CXXFLAGS += -Wno-uninitialized
