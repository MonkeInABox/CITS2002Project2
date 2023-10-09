PROJECT =  mysync
HEADERS =  $(PROJECT).h
OBJ     =  mysync.o directoryContents.o copyfile.o globals.o



C11     =  cc -std=c11
CFLAGS  =  -Wall -Werror 


$(PROJECT) : $(OBJ)
	$(C11) $(CFLAGS) -o $(PROJECT) $(OBJ) -lm


%.o : %.c $(HEADERS)
	$(C11) $(CFLAGS) -c $<

clean:
	rm -f $(PROJECT) $(OBJ)