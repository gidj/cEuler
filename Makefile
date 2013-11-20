TARGET = example
# Compiler and compiling flags:

vpath %.c src
vpath %.h include

CC 		= cc
CFLAGS  = -std=c99 -Wall -I.
# Linker and linking flags:
LINKER 	= cc -o
LFLAGS 	= -Wall -I. -lm  

rm 		= rm -f 

# INCDIR for header files, SRCDIR for .c files, OBJDIR for .o files, and BINDIR for executables
SRCDIR 	= src
OBJDIR 	= obj
BINDIR 	= bin

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

includes:  
	@echo These are the includes: $(INCLUDES)
	@echo These are the sources: $(SOURCES)
	@echo These are the objects: $(OBJECTS)

#$(BINDIR)/$(TARGET): $(OBJECTS)
$(TARGET): $(TARGET).o $(OBJECTS) 
	@$(LINKER) $@ $(LFLAGS) $(OBJECTS) $(TARGET).o
	@echo "Linking complete!"

$(TARGET).o: $(TARGET).c 
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"	

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"	

#.PHONEY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONEY: remove
	remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"

