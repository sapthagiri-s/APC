OBJ := $(patsubst %.c, %.o, $(wildcard *.c)) # Generate a list of object files from all C source files in the directory
apc.exe : $(OBJ)                           # Define the target executable and its dependencies
	gcc -o $@ $^                            # Compile and link the object files into the executable
clean :                                     # Define the clean target to remove generated files
	rm *.exe *.o                            # Remove all .exe and .o files
