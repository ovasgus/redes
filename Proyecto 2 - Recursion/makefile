CC = gcc
OBJS = funciones.o

pargrep: hilos.c funciones.o
			$(CC) $(OBJS) -g -o $@ hilos.c -lpthread
			
funciones.o: funciones.c funciones.h
			$(CC) -c funciones.c funciones.h
			
clean:
			rm -f *.o
	
		
