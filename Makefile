# -- Toutes les cibles seront executées en même temps
all: exec

main.o : candy.c
	gcc -c candy.c -o main.o
	
check.o : check.c
	gcc -c chec.c -o check.o
	
movement.o : movement.c
	gcc -c movement.c -o movement.o

show.o : show.c
	gcc -c show.c -o show.o
	
symbol.o : symbol.c
	gcc -c symbol.c -o symbol.o

exec : main.o
	gcc -c main.o check.o symbol.o show.o movement.o -o exec

# -- Supprime tous les fichiers objects
clean:
	rm -f *.o
	rm exec
