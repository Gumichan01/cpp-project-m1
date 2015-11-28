
#
# Makefile Projet C++
#
#

# Compilateur
CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

# Objets 
OBJS=Afficheur.o Jeu.o Joueur.o JoueurIA.o Strategie.o

# Chemin
FRAMEWORK_PATH=./


# Cibles
#LIB_TARGET=libFramework.a

#all : library

#library: $(LIB_TARGET)


#$(LIB_TARGET) : $(OBJS)
#	@ar rcs 

Afficheur.o : $(FRAMEWORK_PATH)Afficheur.cpp $(FRAMEWORK_PATH)Afficheur.hpp
	g++ -c -o $@ $< $(CFLAGS)
	
	
	
clean:
	rm -f *.o
