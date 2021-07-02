
a.out: main.o libmycode.a
	gcc -g --static main.o -lmycode -L.

main.o: main.c myfunc1.h myfunc2.h
	gcc -c -g main.c
	
libmycode.a: myfunc1.o myfunc2.o
	ar -r libmycode.a myfunc1.o myfunc2.o
	
myfunc1.o: myfunc1.c myfunc1.h myfunc2.h
	gcc -c -g myfunc1.c

myfunc2.o: myfunc2.c myfunc2.h
	gcc -c -g myfunc2.c

debug: a.out
	insight a.out

clean:
	rm *.o a.out
