# -- Toutes les cibles seront executées en même temps
all: exec

candy.o : candy.c header.h
	gcc -c candy.c -o candy.o
	
check.o : check.c header.h
	gcc -c check.c -o check.o
	
movement.o : movement.c header.h
	gcc -c movement.c -o movement.o

show.o : show.c header.h
	gcc -c show.c -o show.o
	
symbol.o : symbol.c header.h
	gcc -c symbol.c -o symbol.o

exec : candy.o check.o symbol.o show.o movement.o 
	gcc candy.o check.o symbol.o show.o movement.o -o exec

# -- Supprime tous les fichiers objects
clean:
	rm -f *.o
	rm exec
