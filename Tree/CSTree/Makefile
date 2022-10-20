
CC = g++
LIB = -I ./Header
BUILD_DIR = Build
OUTFILE = $(notdir $(shell pwd))

CPP = $(wildcard Source/*.cpp)
OBJ = $(patsubst Source/%.cpp, $(BUILD_DIR)/%.o, $(CPP))

.PHONY: all mk_dir clean debug

all: mk_dir $(OUTFILE)

mk_dir:
	if [[ ! -d $(BUILD_DIR) ]]; then mkdir $(BUILD_DIR); fi

$(OUTFILE): $(OBJ)
	$(CC) $^ -o $@ $(DEBUG)

$(OBJ): $(BUILD_DIR)/%.o: Source/%.cpp
	$(CC) -c $(LIB) $^ -o $@ $(DEBUG)

debug:
	make clean
	make DEBUG=-g

clean:
	cd $(BUILD_DIR) && rm -f ./*
	if [[ -e $(OUTFILE) ]]; then rm $(OUTFILE); fi
