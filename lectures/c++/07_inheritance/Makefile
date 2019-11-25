SRC = 00_first_trial.cc         \
      01_inheritance.cc         \
      02_virtual.cc             \
      03_virtual_destructor.cc  \
      04_private.cc             \
      05_dynamic_cast.cc        \
      06_template.cc            \
      07_using.cc


CXX = c++
CXXFLAGS = -W -Wall -Wextra -g -std=c++11

CXXFLAGS += -I ../06_error_handling  # needed by the compiler to find the header

VPATH = ../06_error_handling # needed by makefile to look for files

EXE = $(SRC:.cc=.x)

# eliminate default suffixes
.SUFFIXES:
SUFFIXES =

# just consider our own suffixes
.SUFFIXES: .cc .x

all: $(EXE)

.PHONY: all

%.x: %.cc ap_error.h
	$(CXX) $< -o $@ $(CXXFLAGS)

format: $(SRC)
	@clang-format -i $^ -verbose || echo "Please install clang-format to run this command"
	+$(MAKE) $@ -C organized

.PHONY: format

clean:
	rm -f $(EXE) *~
	+$(MAKE) $@ -C organized

.PHONY: clean

