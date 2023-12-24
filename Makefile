CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= chirp
OBJECTS	= 

all: main

main: $(BUILD)/main.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ $(ARGS) -c

init:
	mkdir $(BUILD)

run:
	./$(BINARY)

clean:
	rm $(BUILD)/*.o

