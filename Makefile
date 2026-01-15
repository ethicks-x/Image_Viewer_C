CC = gcc
CFLAGS = -Wall -Wextra -g -std=c17
SDL2_LINK = `sdl2-config --cflags --libs`
TARGET = pom_i
SRCS = main.c 

all: $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS) $(SDL2_LINK)

clean:
	rm $(TARGET)
