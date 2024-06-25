.POSIX:
CXX = clang++
CXXFLAGS = -g -std=c++20 -Wall -Wextra -MMD -MP

SRCS =	main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

EXE = 1982a-soccer.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)

clean:
	rm -f $(EXE) $(OBJS) $(DEPS)
run: $(EXE)
	./$(EXE)

.PHONY: all clean run
