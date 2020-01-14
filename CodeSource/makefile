# Déclaration des variables
CC=g++
CFLAGS=-c -Wall

all : afficheur main.o Afficheur.o Ligne.o PortSerieAfficheur.o DateHeure.o

PortSerieAfficheur.o : PortSerieAfficheur.cpp PortSerieAfficheur.h
	$(CC) $(CFLAGS) PortSerieAfficheur.cpp

Ligne.o : Ligne.cpp Ligne.h
	$(CC) $(CFLAGS) Ligne.cpp

Afficheur.o : Afficheur.cpp Afficheur.h
	$(CC) $(CFLAGS) Afficheur.cpp
	
DateHeure.o : DateHeure.cpp DateHeure.h
	$(CC) $(CFLAGS) DateHeure.cpp

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

afficheur : main.o Afficheur.o Ligne.o PortSerieAfficheur.o DateHeure.o
	$(CC) main.o Afficheur.o Ligne.o PortSerieAfficheur.o DateHeure.o -o afficheur

clean :
	rm -f *.o afficheur