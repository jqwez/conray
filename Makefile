CC = gcc
CFLAGS = -I./include -Wall
TARGET = conray

INCLUDE = -I./include -I./lib/raylib/include -I./lib/raylib/lib
LINKING = -L./lib/raylib/lib -lraylib 

SRC = $(wildcard src/*.c)


all: $(TARGET)

run:
	@bin/$(TARGET)

$(TARGET):
	$(CC) -o bin/$(TARGET) $(SRC) $(INCLUDE) $(LINKING)

clean:
	rm -f src/*.o $(TARGET)

.PHONY: all clean

