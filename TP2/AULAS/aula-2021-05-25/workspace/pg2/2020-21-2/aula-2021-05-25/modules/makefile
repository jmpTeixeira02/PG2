OUTPUT = prog

LDFLAGS = -g -o $(OUTPUT)

CFLAGS = -c -g --std=c99

$(OUTPUT): main.o myfunc1.o myfunc2.o
	gcc $(LDFLAGS) main.o myfunc1.o myfunc2.o

main.o: main.c myfunc1.h myfunc2.h
	gcc $(CFLAGS) main.c

myfunc1.o: myfunc1.c myfunc1.h myfunc2.h
	gcc $(CFLAGS) myfunc1.c

myfunc2.o: myfunc2.c myfunc2.h
	gcc $(CFLAGS) myfunc2.c

debug: a.out
	insight $(OUTPUT)

clean:
	rm *.o $(OUTPUT)
