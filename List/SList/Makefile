CC = g++
LIB = -I ./Header
BUILD_DIR = Build
OUTFILE = SList

CPP = $(wildcard Source/*.cpp)
OBJ = $(patsubst Source/%.cpp, $(BUILD_DIR)/%.o, $(CPP))

.PHONY: all mk_dir clean

all: mk_dir $(OUTFILE)

mk_dir:
	if [[ ! -d $(BUILD_DIR) ]]; then mkdir $(BUILD_DIR); fi
	echo $(OBJ)

$(OUTFILE): $(OBJ)
	$(CC) $^ -o $@

$(OBJ): $(BUILD_DIR)/%.o: Source/%.cpp 
	$(CC) -c $(LIB) $^ -o $@


clean:
	rm $(OUTFILE)
	cd $(BUILD_DIR) && rm -f ./*
