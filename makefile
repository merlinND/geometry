COMPILER=g++
CPPFLAGS=-w -Wall
LINKER=@g++
LINKERFLAGS=
INCPATH=
LIBPATH=

ECHO=@echo
CLEAN=clean

SRCDIR=src
OUTPUTDIR=bin
EXE=geometry

FILES=Controller.h geometricObjects/Agregate.h geometricObjects/Circle.h geometricObjects/GeometricObject.h geometricObjects/Line.h geometricObjects/Polyline.h geometricObjects/Rectangle.h commands/AddCommand.h commands/ClearCommand.h commands/Command.h commands/CommandInterpreter.h commands/DeleteCommand.h commands/ExitCommand.h commands/History.h commands/ListCommand.h commands/LoadCommand.h commands/MoveCommand.h commands/NoneCommand.h commands/RedoCommand.h commands/SaveCommand.h commands/UndoCommand.h

HEADERS=$(addprefix $(SRCDIR)/,$(FILES))
IMPL=$(HEADERS:.h=.cpp)

OBJ=$(addprefix $(OUTPUTDIR)/,$(FILES:.h=.o))
OBJ+=$(OUTPUTDIR)/geometry.o

.PHONY: $(CLEAN)
ALL: $(EXE)

# Ouput executable
$(EXE): $(OBJ)
	$(ECHO) Linking $(EXE)...
	$(LINKER) $(LINKERFLAGS) $(INCPATH) -o $(OUTPUTDIR)/$(EXE) $(OBJ) $(LIBS)

# Generic rule
$(OUTPUTDIR)/%.o: $(SRCDIR)/%.cpp
	$(ECHO) Compiling $<...
	$(COMPILER) $(CPPFLAGS) $(INCPATH) -o $@ -c $<

# Explicit dependancies
$(OUTPUTDIR)/Agregate.o: $(SRCDIR)/GeometricObject.h
$(OUTPUTDIR)/GraphGenerator.o: $(SRCDIR)/LogAnalyser.h
$(OUTPUTDIR)/LogAnalyser.o: $(SRCDIR)/LogEntry.h $(SRCDIR)/ApacheLogParser.h $(SRCDIR)/LogAnalyserTypes.h
$(OUTPUTDIR)/LogEntry.o: $(SRCDIR)/Date.h
$(OUTPUTDIR)/TP4.o: $(SRCDIR)/LogAnalyser.h $(SRCDIR)/GraphGenerator.h

$(CLEAN):
	$(ECHO) Cleaning project.
	rm -f $(OBJ) $(OUTPUTDIR)/$(EXE) core
