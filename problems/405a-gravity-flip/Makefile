.POSIX:
CXX = clang++
CXXFLAGS = -g -std=c++20 -Wall -Wextra -MMD -MP

SRCS =	main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

EXE = 405a-gravity-flip.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

-include $(DEPS)

clean:
	rm -f $(EXE) $(OBJS) $(DEPS)
run: $(EXE)
	./$(EXE)

.PHONY: all clean run
