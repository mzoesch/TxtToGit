
TARGET := output
FLAGS_FOR_APP = ./.flags
TMP_CONFIG = ./.tmp.txt

OBJ := ./obj
SRC_DIRS := ./src

CC := g++

SRCS := $(shell find $(SRC_DIRS) -name '*.cpp' -or -name '*.c' -or -name '*.s')
OBJS := $(SRCS:%=$(OBJ)/%.o)


DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS := $(INC_FLAGS) -MMD -MP -std=c++14

$(OBJ)/$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.c.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJ)/%.cpp.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean
clean:
	-rm -r $(OBJ)/*
	-rm -r $(OBJ)/.*
	-rm -r $(OBJ)/*.*
	-touch $(OBJ)/.gitkeep
	-rm $(FLAGS_FOR_APP)
	-rm $(TMP_CONFIG)

-include $(DEPS)
