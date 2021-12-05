CFLAGS = -Wall -Wextra -Wpedantic
CC = g++
LDFLAGS = -lpthread -lgtest
SOURCES = main.cpp tests.cpp Prime.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = program

#Rule which build all project
all: clean $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

#Rule to build obj files
$(OBJECTS): 
	$(CC) -c $(CFLAGS) $(SOURCES)

#Rule to clean
clean: 
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)