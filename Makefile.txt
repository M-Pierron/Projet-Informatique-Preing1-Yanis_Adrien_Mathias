# -- Toutes les cibles seront executées en même temps
all: exec

main.o : *c
	gcc -c *.c -o main.o

exec : main.o
	gcc -c main.o -o exec

# -- Supprime tous les fichiers objects
clean:
	rm -f *.o
	rm exec
