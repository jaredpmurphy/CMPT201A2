CFLAGS=-Wall --std=c11
outName=appGame
outDir=bin
srcDir=src
SRC=$(wildcard $(srcDir)/*.c)
OBJ=$(SRC:.c=.o)
HDR=$(wildcard $(srcDir)/*.h)

$(outName): $(OBJ) $(HDR)
	$(CC) $(CFLAGS) $^ -o $(outDir)/$@ -lm -lc -lncurses -ltinfo

debug: $(OBJ) $(HDR)
	$(CC) $(CFLAGS) -g $^ -o $(outDir)/$@ -lm -lc -lncurses -ltinfo
	
%.o:%.c
	$(CC) $(CFLAGS) -c -g $^ -o $@

.Phony:clean run_debug run_valgrind Doc

clean:
	rm -rf $(outDir)/* *.o debug doc/html/* doc/latex/*

run_debug: debug
	gdb ./debug

Mem_valgrind: debug
	valgrind --track-origins=yes --leak-check=full ./bin/debug

Doc: $(SRC) $(HDR)
	doxygen doxy.conf