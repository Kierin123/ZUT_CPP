CFLAGS = -Wall -Wextra -Wpedantic -g
CC = g++
LDFLAGS =  -lMyPtr 
SOURCES =  main.cpp 
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = program


#Rule which build all project
all: clean $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE) 
	
#Rule to build obj files
$(OBJECTS): 
	$(CC) -c $(CFLAGS) $(SOURCES) 

#Rule to clean
clean: 
	rm -f $(OBJECTS)
	rm -f $(EXECUTABLE)