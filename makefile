CC=gcc
CFLAGS=lm

polynomrechner: main.o berechnung.o grafik.o
	$(CC) -o polynomrechner main.o berechnung.o grafik.o -$(CFLAGS)
