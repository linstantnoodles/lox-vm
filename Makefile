CC=gcc
CFLAGS=-g
PROGNAME=clox

# runs if no args passed to 'make' command
all: compile

# compiles and links, outputting single binary
# $^ is auto variable for the list of deps
# compile: main.o memory.o chunk.o debug.o value.o
# 	$(CC) $(CFLAGS) -o $(PROGNAME) $^
# 	@chmod +x $(PROGNAME)

compile: main.o memory.o chunk.o debug.o value.o vm.o scanner.o compiler.o
	$(CC) $(CFLAGS) -o $(PROGNAME) $^
	@chmod +x $(PROGNAME)

# create object files with matching names to C files
%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm *.o $(PROGNAME)

run:
	@./$(PROGNAME)

dev: compile run
