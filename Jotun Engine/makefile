# Makefile to compile the Core as a shared library
# Libraries
# C++11/14 options
# something else I guess?

CC=clang
VERSION=-std=c++11
OPTS=-c -fPIC
LIBNAME=Core.so
SHARED=-shared -Wl,-soname,$(LIBNAME)
DEBUG=-g
SOURCES=CYamlParser.cpp
OBJECTS=$(SOURCES: .cpp=.o)

all: $(OBJECTS)
	$(CC) $(VERSION) $(SHARED) $(DEBUG) $(OBJECTS)

$(OBJECTS): $(SOURCES)
	$(CC) $(VERSION) $(OPTS) $(DEBUG) $(SOURCES)
