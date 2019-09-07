CC := gcc
CFLAGS := -Wall -O3
Libs = -lpthread -lsqlite3
Target := server
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += configure handle main
AllObjs := $(addsuffix /src/*.o,$(Modules))

