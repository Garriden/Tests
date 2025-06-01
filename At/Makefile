CC = g++
RM = rm -f
CPPFLAGS = -g -Wall -std=c++11  # Added -Wall and -std=c++11
LDFLAGS = -g

# Add your .cpp source files here, separated by spaces
SRCS = main.cpp file.cpp utils.cpp

OBJS = $(SRCS:.cpp=.o)  # Corrected: .cpp to .o

all: main

main: $(OBJS)
    $(CC) $(LDFLAGS) $(OBJS) -o main

%.o: %.cpp  # Corrected: %.c to %.cpp
    $(CC) $(CPPFLAGS) -c $< -o $@ # Added -o $@

clean:
    $(RM) $(OBJS)

dist-clean: clean
    $(RM) main