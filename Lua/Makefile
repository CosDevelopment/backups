CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash
PROGRAMS=	src/dijkstras


all:		main

dijkstras:	main.cpp
	$(CXX) $(CXXFLAGS) lapi.c lcode.c lctype.c ldebug.c ldo.c ldump.c lfunc.c lgc.c llex.c lmem.c lobject.c lopcodes.c lparser.c lstate.c lstring.c ltable.c ltm.c lundump.c lvm.c lzio.c lauxlib.c lbaselib.c lbitlib.c lcorolib.c ldblib.c liolib.c lmathlib.c loslib.c lstrlib.c ltablib.c lutf8lib.c loadlib.c linit.c -o $@ $^
