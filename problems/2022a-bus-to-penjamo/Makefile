.POSIX:
CXX = clang++
CXXFLAGS = -g -std=c++23 -Wall -Wextra

SRCS =	main.cpp
OBJS = $(SRCS:.cpp=.o)

EXE = 2022a-bus-to-penjamo.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(EXE) $(OBJS)
run: $(EXE)
	./$(EXE)

.PHONY: all clean run
