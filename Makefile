SRC_DIR ?= ./
SRC_DIRS ?= $(shell find $(SRC_DIR) -type d)
INC_FLAGS := $(addprefix -I,$(SRC_DIRS))

SRCS := $(shell find $(SRC_DIR) -name "*.cpp")
OBJS := $(SRCS:.cpp=.o)
DEPS := $(OBJS:.o=.d)

CXX = g++

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

MAIN = ./a.out

.PHONY: depend clean

$(MAIN): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -o $(MAIN) $(OBJS)  

.c.o:
	$(CXX) $(CXXFLAGS) $(INC_FLAGS) -c $<  -o $@

clean:
	$(RM) $(OBJS) $(DEPS) $(MAIN)


depend: $(SRCS)
	makedepend $(INC_FLAGS) $^


# DO NOT DELETE

src/main/runner/initializr.o: src/main/runner/initializr.h
src/main/runner/initializr.o: src/test/runner/initializr.h
src/main/runner/initializr.o: src/main/util/logger.h
src/main/runner/initializr.o: src/main/runner/configs.h src/main/util/enums.h
src/main/runner/initializr.o: src/main/util/consts.h src/main/util/enums.h
src/main/runner/initializr.o: src/main/util/utilities.h
src/main/runner/initializr.o: src/test/entity/field_test.h
src/main/runner/initializr.o: src/main/entity/field.h src/main/util/consts.h
src/main/runner/initializr.o: src/test/entity/minefield_test.h
src/main/runner/initializr.o: src/main/entity/minefield.h
src/main/runner/initializr.o: src/main/util/utilities.h
src/main/runner/initializr.o: src/main/util/logger.h src/main/entity/field.h
src/main/runner/initializr.o: src/test/entity/player_test.h
src/main/runner/initializr.o: src/main/entity/player.h src/main/logic/game.h
src/main/runner/initializr.o: src/main/entity/field.h
src/main/runner/initializr.o: src/main/entity/minefield.h
src/main/runner/initializr.o: src/main/entity/player.h
src/main/util/logger.o: src/main/util/logger.h src/main/runner/configs.h
src/main/util/logger.o: src/main/util/enums.h src/main/util/consts.h
src/main/util/logger.o: src/main/util/enums.h
src/main/util/utilities.o: src/main/util/utilities.h
src/main/util/utilities.o: src/main/runner/configs.h src/main/util/enums.h
src/main/entity/field.o: src/main/entity/field.h
src/main/entity/player.o: src/main/entity/player.h src/main/util/consts.h
src/main/entity/minefield.o: src/main/entity/minefield.h
src/main/entity/minefield.o: src/main/runner/configs.h src/main/util/enums.h
src/main/entity/minefield.o: src/main/util/consts.h src/main/util/utilities.h
src/main/entity/minefield.o: src/main/util/logger.h src/main/entity/field.h
src/main/logic/game.o: src/main/logic/game.h src/main/util/consts.h
src/main/logic/game.o: src/main/util/utilities.h src/main/entity/field.h
src/main/logic/game.o: src/main/entity/minefield.h src/main/entity/player.h
src/test/runner/initializr.o: src/main/runner/initializr.h
src/test/runner/initializr.o: src/test/runner/initializr.h
src/test/runner/initializr.o: src/main/util/logger.h
src/test/runner/initializr.o: src/main/runner/configs.h src/main/util/enums.h
src/test/runner/initializr.o: src/main/util/consts.h src/main/util/enums.h
src/test/runner/initializr.o: src/main/util/utilities.h
src/test/runner/initializr.o: src/test/entity/field_test.h
src/test/runner/initializr.o: src/main/entity/field.h src/main/util/consts.h
src/test/runner/initializr.o: src/test/entity/minefield_test.h
src/test/runner/initializr.o: src/main/entity/minefield.h
src/test/runner/initializr.o: src/main/util/utilities.h
src/test/runner/initializr.o: src/main/util/logger.h src/main/entity/field.h
src/test/runner/initializr.o: src/test/entity/player_test.h
src/test/runner/initializr.o: src/main/entity/player.h src/main/logic/game.h
src/test/runner/initializr.o: src/main/entity/field.h
src/test/runner/initializr.o: src/main/entity/minefield.h
src/test/runner/initializr.o: src/main/entity/player.h
src/test/entity/player_test.o: src/test/entity/player_test.h
src/test/entity/player_test.o: src/main/util/logger.h
src/test/entity/player_test.o: src/main/runner/configs.h
src/test/entity/player_test.o: src/main/util/enums.h src/main/util/consts.h
src/test/entity/player_test.o: src/main/util/enums.h src/main/entity/player.h
src/test/entity/player_test.o: src/main/util/consts.h
src/test/entity/field_test.o: src/test/entity/field_test.h
src/test/entity/field_test.o: src/main/util/logger.h
src/test/entity/field_test.o: src/main/runner/configs.h src/main/util/enums.h
src/test/entity/field_test.o: src/main/util/consts.h src/main/util/enums.h
src/test/entity/field_test.o: src/main/entity/field.h src/main/util/consts.h
src/test/entity/minefield_test.o: src/test/entity/minefield_test.h
src/test/entity/minefield_test.o: src/main/util/logger.h
src/test/entity/minefield_test.o: src/main/runner/configs.h
src/test/entity/minefield_test.o: src/main/util/enums.h
src/test/entity/minefield_test.o: src/main/util/consts.h
src/test/entity/minefield_test.o: src/main/util/enums.h
src/test/entity/minefield_test.o: src/main/entity/minefield.h
src/test/entity/minefield_test.o: src/main/util/consts.h
src/test/entity/minefield_test.o: src/main/util/utilities.h
src/test/entity/minefield_test.o: src/main/util/logger.h
src/test/entity/minefield_test.o: src/main/entity/field.h
main.o: src/main/runner/initializr.h src/test/runner/initializr.h
main.o: src/main/util/logger.h src/main/runner/configs.h
main.o: src/main/util/enums.h src/main/util/consts.h src/main/util/enums.h
main.o: src/main/util/utilities.h src/test/entity/field_test.h
main.o: src/main/entity/field.h src/main/util/consts.h
main.o: src/test/entity/minefield_test.h src/main/entity/minefield.h
main.o: src/main/util/utilities.h src/main/util/logger.h
main.o: src/main/entity/field.h src/test/entity/player_test.h
main.o: src/main/entity/player.h src/main/logic/game.h
main.o: src/main/entity/field.h src/main/entity/minefield.h
main.o: src/main/entity/player.h
