# architecture
ARCH = $(shell uname -p)
BITS = $(shell uname -m)
OS = $(shell uname) 
OSFLAVOR =

USERMACROS = -DNDEBUG -DTHREADED
CFLAGS = -Wall -pedantic -O3 -fomit-frame-pointer -fstrict-aliasing -ffast-math -std=c++0x -pthread -I../common
DFLAGS =
LFLAGS = -lpthread -lrt
INSTALL = /usr/local/bin
EXE_BITS =
EXE_OS =
THREADED =
GIT_VERSION =
# build info
SRC := main.cpp

# compiler
ifeq ($(COMP),)
   CC = g++
else
   CC = $(COMP)
endif

# arch
ifeq ($(ARCH),i386)
   CFLAGS += -sse
   CFLAGS += -O2
endif

# bits
ifeq ($(BITS),x86_64)
   EXE_BITS = 64
   CFLAGS += -m64
   USERMACROS += -DBIT_64
else
   EXE_BITS = 32
   CFLAGS += -m32
   USERMACROS += -DBIT_32
endif

# prefetch
ifeq ($(USE_PREFETCH),true)
   USERMACROS += -DUSE_PREFETCH
endif

# os
ifeq ($(OS),Darwin )
   EXE_OS = osx
   USERMACROS += -DOS=\"unix\"
endif

ifeq ($(OS),Linux )
   EXE_OS = nix
   USERMACROS += -DOS=\"unix\"
endif

# executable
EXE = sorting.exe

# git version info
GIT_VERSION := $(shell git describe --abbrev=4 --dirty --always --tags)
USERMACROS += -DBUILD_DATE="\"$$(date)\""
USERMACROS += -DVERSION=\"$(GIT_VERSION)\"

OBJ := $(patsubst %.cpp, %.o, $(filter %.cpp,$(SRC)))

.PHONY:all
all: information link

debug: CFLAGS += -g -ggdb
debug: USERMACROS:=$(filter-out -DNDEBUG, $(USERMACROS))
debug: USERMACROS += -DDEBUG
debug: all

information:
	@echo ".............................."
	@echo "...ARCH    = "$(ARCH)
	@echo "...BITS    = "$(BITS)
	@echo "...CC      = "$(CC)
	@echo "...OS      = "$(OS)
	@echo "...CFLAGS  = "$(CFLAGS)
	@echo "...MACROS  = "$(USERMACROS)
	@echo "...EXE     = "$(EXE)
	@echo "..............................."
	@echo ""

link: $(OBJ)
	$(CC) -o $(EXE) $(OBJ) $(LFLAGS)


%.o:%.cpp
	$(CC) -c $(CFLAGS) $(USERMACROS) $< -o $@

install: all
	if [ ! -d $(INSTALL) ]; then \
		mkdir -p $(INSTALL); \
	fi 
	mv $(EXE) $(INSTALL)
	find . -name "*.o" | xargs rm -vf 

TAGS:   $(SRC)
	etags $(SRC)

depend:
	makedepend -- $(DFLAGS) -- $(SRC)

.PHONY:clean
clean:
	find . -name "*.o" | xargs rm -vf
	find . -name "*.ii" | xargs rm -vf
	find . -name "*.s" | xargs rm -vf
	rm -vf *~ *#
