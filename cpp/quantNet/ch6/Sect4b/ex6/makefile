#OBJS specifies which files to compile as part of project
OBJS = 4-4b-6.cpp Point.cpp Line.cpp Array.cpp Circle.cpp Shape.cpp OutOfBoundsException.cpp NumericArray.cpp PointArray.cpp Stack.cpp StackFullException.cpp StackEmptyException.cpp UniqueSizeException.cpp
#CC specifies which compiler we're using 
CC = g++

#compiler_flags SPECIFIES the additional compilation options
COMPILER_FLAGS = -I. -w -std=c++14

#linker flags
LINKER_FLAGS = 

#OBJ_NAME specifies the name of our executable
OBJ_NAME = ex1


all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

