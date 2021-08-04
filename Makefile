COMPILER = g++
FILESYSTEM_FILES = main.cpp
CFLAGS = -g -std=c++11
LINKFLAGS = -lcrypto

build: $(FILESYSTEM_FILES)
	$(COMPILER) $(CFLAGS) $(FILESYSTEM_FILES) -o reg $(LINKFLAGS)
	ls -lhtr

clean:
	rm reg
