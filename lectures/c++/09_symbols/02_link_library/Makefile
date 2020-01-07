EXE = ap
GDIR=../01_greetings_library

LDFLAGS = -lgreetings -L $(GDIR)
CXX = c++
CXXFLAGS = -I include -I $(GDIR)/include -std=c++11

all: $(EXE)

%.o: %.cc
	$(CXX) -c $< -o $@ $(CXXFLAGS)


$(EXE): main.o src/date.o src/student.o
	$(CXX) $^ -o $(EXE) $(LDFLAGS)

main.o: src/student.o src/date.o

src/date.o: include/date.h

src/student.o: include/student.h

format: $(SRC) include/date.h include/student.h
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands"

clean:
	rm -rf src/*.o *.o $(EXE) */*~ *~ a.out*

.PHONY: clean all format


