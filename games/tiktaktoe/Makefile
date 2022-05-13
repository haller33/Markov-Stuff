TARGET ?= main
SRC_DIRS ?= ./src
BLD_DIRS ?= ./build

LOADLIBES := $(shell find $(SRC_DIRS) -name *.hpp -or -name *.h -or -name *.s)
SRCS      := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
OBJS      := $(addsuffix .o,$(basename $(SRCS)))
DEPS      := $(OBJS:.o=.d)
CC        := c++

INC_DIRS  := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -Wall

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) $(LOADLIBES) $(LDLIBS) $(OBJS) -o $@ 

.PHONY: clean
clean:
	$(RM) $(TARGET) $(OBJS) $(DEPS) $(BLD_DIRS)

-include $(DEPS)
