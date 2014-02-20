CC          =	gcc
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall -ansi -pedantic -g
LDFLAGS     =

#Directories where the compiler can find things
INCLUDES    = -Iinclude
LIBDIRS     = 
LIBS        = 

BINDIR = bin/
SRCDIR = src/

#Put the names of your source code files in the lines below.  

SOURCE = $(SRCDIR)hash.c $(SRCDIR)list.c $(SRCDIR)a2.c 


#The list of object files for each program is below.  
# The object file names here must match the file names of your source code 
# except with .o instead of .c.   Make changes as appropriate


OBJS    = hash.o list.o a2.o 

 #decide what you want your executables to be called.  Because we are actually creating more than
 # one runnable program we need two names.
 
 
 #name for the simulation program
PROGRAM = $(BINDIR)a2

default : all

all : prog


prog : build
	$(CC) $(LIBDIRS) $(LDFLAGS) -o $(PROGRAM) $(OBJS) $(LIBS)


build: $(SOURCE)
	$(CC) $(CFLAGS) -c $(SOURCE) $(INCLUDES)

clean:
	@ rm *.o



run: prog
	$(PROGNAME) 
