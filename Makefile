CFLAGS=-Wall --std=c11
outName=myGame
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
HDR=$(wildcard *.h)

$(outName): $(OBJ) $(HDR)
	$(CC) $(CFLAGS) $^ -o $@ -lm -lc -lncurses -ltinfo

debug: $(OBJ) $(HDR)
	$(CC) $(CFLAGS) -g $^ -o $@ -lm -lc -lncurses -ltinfo
	
%.o:%.c
	$(CC) $(CFLAGS) -c -g $^ -o $@

.Phony:clean run_debug run_valgrind

clean:
	rm -f $(outName) *.o debug

run_debug: debug
	gdb ./debug

run_valgrind: debug
	valgrind -s --track-origins=yes --leak-check=full ./debug