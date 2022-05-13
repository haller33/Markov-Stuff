TARGET_EXEC ?= main

BUILD_DIR ?= ./build
SRC_DIRS  ?= ./src
TAGS_FILE ?= TAGS

SRC_HEADERS := $(shell find $(SRC_DIRS) -name *.hpp)
SRCS := $(shell find $(SRC_DIRS) -name *.cpp)
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
CC   := c++
CXX  := c++

INC_DIRS  := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP -Wall -g

$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(tags)
	$(CC) -o $@ $(LDFLAGS) $(OBJS)

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@


.PHONY: clean

clean:
	$(RM) -r $(BUILD_DIR) $(TAGS_FILE)

tags:
	$(TAGS_EXE) $(SRC_HEADERS) $(SRCS)

run:
	./$(BUILD_DIR)/$(TARGET_EXEC)

-include $(DEPS)

MKDIR_P ?= mkdir -p
TAGS_EXE ?= etags -o $(TAGS_FILE)
