CC		= gcc
ARGS	= -Wall -g
BUILD	= build
BINARY	= chirp
OBJECTS	= $(BUILD)/chirp_mathexp.o

all: repl

main: $(BUILD)/main.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

repl: $(BUILD)/repl.o $(OBJECTS)
	$(CC) $^ -o $(BINARY) $(ARGS)

$(BUILD)/%.o: %.c
	$(CC) $^ -o $@ $(ARGS) -c

init:
	mkdir $(BUILD)

run:
	./$(BINARY)

clean:
	rm $(BUILD)/*.o
