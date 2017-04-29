## --------------------------------------------
## Makefile for mineszwiper-cpp project
## --------------------------------------------

WORKDIR = %cd%

CC = gcc.exe
CXX = g++.exe
AR = ar.exe
LD = g++.exe
WINDRES = windres.exe

INC =
CFLAGS = -Wall -fexceptions
RESINC =
LIBDIR =
LIB =
LDFLAGS =

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj\\Debug
DEP_DEBUG =
OUT_DEBUG = bin\\Debug\\mineszwiper-cpp.exe

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj\\Release
DEP_RELEASE =
OUT_RELEASE = bin\\Release\\mineszwiper-cpp.exe

OBJ_DEBUG = $(OBJDIR_DEBUG)\\src\\test\\runner\\initializr.o $(OBJDIR_DEBUG)\\src\\test\\entity\\player_test.o $(OBJDIR_DEBUG)\\src\\test\\entity\\minefield_test.o $(OBJDIR_DEBUG)\\src\\test\\entity\\field_test.o $(OBJDIR_DEBUG)\\src\\main\\util\\logger.o $(OBJDIR_DEBUG)\\src\\main\\runner\\initializr.o $(OBJDIR_DEBUG)\\src\\main\\logic\\game.o $(OBJDIR_DEBUG)\\src\\main\\entity\\player.o $(OBJDIR_DEBUG)\\src\\main\\entity\\minefield.o $(OBJDIR_DEBUG)\\src\\main\\entity\\field.o $(OBJDIR_DEBUG)\\main.o

OBJ_RELEASE = $(OBJDIR_RELEASE)\\src\\test\\runner\\initializr.o $(OBJDIR_RELEASE)\\src\\test\\entity\\player_test.o $(OBJDIR_RELEASE)\\src\\test\\entity\\minefield_test.o $(OBJDIR_RELEASE)\\src\\test\\entity\\field_test.o $(OBJDIR_RELEASE)\\src\\main\\util\\logger.o $(OBJDIR_RELEASE)\\src\\main\\runner\\initializr.o $(OBJDIR_RELEASE)\\src\\main\\logic\\game.o $(OBJDIR_RELEASE)\\src\\main\\entity\\player.o $(OBJDIR_RELEASE)\\src\\main\\entity\\minefield.o $(OBJDIR_RELEASE)\\src\\main\\entity\\field.o $(OBJDIR_RELEASE)\\main.o

all: debug release

clean: clean_debug clean_release

before_debug:
	cmd /c if not exist bin\\Debug md bin\\Debug
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\test\\runner md $(OBJDIR_DEBUG)\\src\\test\\runner
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\test\\entity md $(OBJDIR_DEBUG)\\src\\test\\entity
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\main\\util md $(OBJDIR_DEBUG)\\src\\main\\util
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\main\\runner md $(OBJDIR_DEBUG)\\src\\main\\runner
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\main\\logic md $(OBJDIR_DEBUG)\\src\\main\\logic
	cmd /c if not exist $(OBJDIR_DEBUG)\\src\\main\\entity md $(OBJDIR_DEBUG)\\src\\main\\entity
	cmd /c if not exist $(OBJDIR_DEBUG) md $(OBJDIR_DEBUG)

after_debug:

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG)

$(OBJDIR_DEBUG)\\src\\test\\runner\\initializr.o: src\\test\\runner\\initializr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\test\\runner\\initializr.cpp -o $(OBJDIR_DEBUG)\\src\\test\\runner\\initializr.o

$(OBJDIR_DEBUG)\\src\\test\\entity\\player_test.o: src\\test\\entity\\player_test.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\test\\entity\\player_test.cpp -o $(OBJDIR_DEBUG)\\src\\test\\entity\\player_test.o

$(OBJDIR_DEBUG)\\src\\test\\entity\\minefield_test.o: src\\test\\entity\\minefield_test.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\test\\entity\\minefield_test.cpp -o $(OBJDIR_DEBUG)\\src\\test\\entity\\minefield_test.o

$(OBJDIR_DEBUG)\\src\\test\\entity\\field_test.o: src\\test\\entity\\field_test.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\test\\entity\\field_test.cpp -o $(OBJDIR_DEBUG)\\src\\test\\entity\\field_test.o

$(OBJDIR_DEBUG)\\src\\main\\util\\logger.o: src\\main\\util\\logger.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\main\\util\\logger.cpp -o $(OBJDIR_DEBUG)\\src\\main\\util\\logger.o

$(OBJDIR_DEBUG)\\src\\main\\runner\\initializr.o: src\\main\\runner\\initializr.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\main\\runner\\initializr.cpp -o $(OBJDIR_DEBUG)\\src\\main\\runner\\initializr.o

$(OBJDIR_DEBUG)\\src\\main\\logic\\game.o: src\\main\\logic\\game.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\main\\logic\\game.cpp -o $(OBJDIR_DEBUG)\\src\\main\\logic\\game.o

$(OBJDIR_DEBUG)\\src\\main\\entity\\player.o: src\\main\\entity\\player.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\main\\entity\\player.cpp -o $(OBJDIR_DEBUG)\\src\\main\\entity\\player.o

$(OBJDIR_DEBUG)\\src\\main\\entity\\minefield.o: src\\main\\entity\\minefield.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\main\\entity\\minefield.cpp -o $(OBJDIR_DEBUG)\\src\\main\\entity\\minefield.o

$(OBJDIR_DEBUG)\\src\\main\\entity\\field.o: src\\main\\entity\\field.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c src\\main\\entity\\field.cpp -o $(OBJDIR_DEBUG)\\src\\main\\entity\\field.o

$(OBJDIR_DEBUG)\\main.o: main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c main.cpp -o $(OBJDIR_DEBUG)\\main.o

clean_debug:
	cmd /c del /f $(OBJ_DEBUG) $(OUT_DEBUG)
	cmd /c rd bin\\Debug
	cmd /c rd $(OBJDIR_DEBUG)\\src\\test\\runner
	cmd /c rd $(OBJDIR_DEBUG)\\src\\test\\entity
	cmd /c rd $(OBJDIR_DEBUG)\\src\\main\\util
	cmd /c rd $(OBJDIR_DEBUG)\\src\\main\\runner
	cmd /c rd $(OBJDIR_DEBUG)\\src\\main\\logic
	cmd /c rd $(OBJDIR_DEBUG)\\src\\main\\entity
	cmd /c rd $(OBJDIR_DEBUG)

before_release:
	cmd /c if not exist bin\\Release md bin\\Release
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\test\\runner md $(OBJDIR_RELEASE)\\src\\test\\runner
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\test\\entity md $(OBJDIR_RELEASE)\\src\\test\\entity
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\main\\util md $(OBJDIR_RELEASE)\\src\\main\\util
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\main\\runner md $(OBJDIR_RELEASE)\\src\\main\\runner
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\main\\logic md $(OBJDIR_RELEASE)\\src\\main\\logic
	cmd /c if not exist $(OBJDIR_RELEASE)\\src\\main\\entity md $(OBJDIR_RELEASE)\\src\\main\\entity
	cmd /c if not exist $(OBJDIR_RELEASE) md $(OBJDIR_RELEASE)

after_release:

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)\\src\\test\\runner\\initializr.o: src\\test\\runner\\initializr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\test\\runner\\initializr.cpp -o $(OBJDIR_RELEASE)\\src\\test\\runner\\initializr.o

$(OBJDIR_RELEASE)\\src\\test\\entity\\player_test.o: src\\test\\entity\\player_test.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\test\\entity\\player_test.cpp -o $(OBJDIR_RELEASE)\\src\\test\\entity\\player_test.o

$(OBJDIR_RELEASE)\\src\\test\\entity\\minefield_test.o: src\\test\\entity\\minefield_test.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\test\\entity\\minefield_test.cpp -o $(OBJDIR_RELEASE)\\src\\test\\entity\\minefield_test.o

$(OBJDIR_RELEASE)\\src\\test\\entity\\field_test.o: src\\test\\entity\\field_test.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\test\\entity\\field_test.cpp -o $(OBJDIR_RELEASE)\\src\\test\\entity\\field_test.o

$(OBJDIR_RELEASE)\\src\\main\\util\\logger.o: src\\main\\util\\logger.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\main\\util\\logger.cpp -o $(OBJDIR_RELEASE)\\src\\main\\util\\logger.o

$(OBJDIR_RELEASE)\\src\\main\\runner\\initializr.o: src\\main\\runner\\initializr.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\main\\runner\\initializr.cpp -o $(OBJDIR_RELEASE)\\src\\main\\runner\\initializr.o

$(OBJDIR_RELEASE)\\src\\main\\logic\\game.o: src\\main\\logic\\game.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\main\\logic\\game.cpp -o $(OBJDIR_RELEASE)\\src\\main\\logic\\game.o

$(OBJDIR_RELEASE)\\src\\main\\entity\\player.o: src\\main\\entity\\player.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\main\\entity\\player.cpp -o $(OBJDIR_RELEASE)\\src\\main\\entity\\player.o

$(OBJDIR_RELEASE)\\src\\main\\entity\\minefield.o: src\\main\\entity\\minefield.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\main\\entity\\minefield.cpp -o $(OBJDIR_RELEASE)\\src\\main\\entity\\minefield.o

$(OBJDIR_RELEASE)\\src\\main\\entity\\field.o: src\\main\\entity\\field.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c src\\main\\entity\\field.cpp -o $(OBJDIR_RELEASE)\\src\\main\\entity\\field.o

$(OBJDIR_RELEASE)\\main.o: main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c main.cpp -o $(OBJDIR_RELEASE)\\main.o

clean_release:
	cmd /c del /f $(OBJ_RELEASE) $(OUT_RELEASE)
	cmd /c rd bin\\Release
	cmd /c rd $(OBJDIR_RELEASE)\\src\\test\\runner
	cmd /c rd $(OBJDIR_RELEASE)\\src\\test\\entity
	cmd /c rd $(OBJDIR_RELEASE)\\src\\main\\util
	cmd /c rd $(OBJDIR_RELEASE)\\src\\main\\runner
	cmd /c rd $(OBJDIR_RELEASE)\\src\\main\\logic
	cmd /c rd $(OBJDIR_RELEASE)\\src\\main\\entity
	cmd /c rd $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release

