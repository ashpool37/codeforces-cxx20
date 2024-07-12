.POSIX:
CXX = clang++
CXXFLAGS = -g -std=c++20 -Wall -Wextra

SRCS =	main.cpp
OBJS = $(SRCS:.cpp=.o)

EXE = 1512a-spy-detected.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(EXE) $(OBJS)
run: $(EXE)
	./$(EXE)

.PHONY: all clean run
