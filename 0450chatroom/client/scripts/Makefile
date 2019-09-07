CC := gcc
CFLAGS := -Wall -O3
Libs = -lpthread -lsqlite3
Target := client
Source := $(wildcard src/*.c)
Objs := $(patsubst %.c,%.o,$(Source))
Modules += configure listen_server user main
AllObjs := $(addsuffix /src/*.o,$(Modules))

