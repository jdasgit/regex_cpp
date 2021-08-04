COMPILER = g++
FILESYSTEM_FILES = main.cpp
CFLAGS = -g -std=c++11

build: $(FILESYSTEM_FILES)
	$(COMPILER) $(CFLAGS) $(FILESYSTEM_FILES) -o reg
	ls -lhtr

clean:
	rm reg
