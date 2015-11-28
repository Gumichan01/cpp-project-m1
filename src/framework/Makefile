
#
# Makefile Projet C++
#
#

# Compilateur
CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

# Objets 
SRC=Afficheur.cpp Jeu.cpp Joueur.cpp JoueurIA.cpp Strategie.cpp
OBJS=$(SRC:.cpp=.o)

# Chemin
FRAMEWORK_PATH=./


# Cibles
LIB_TARGET=../libDiderot.a


all : library
library: $(LIB_TARGET)

$(LIB_TARGET) : $(OBJS)
	ar rcs $@ $^



#
# Compilation des objets
#

Afficheur.o: $(FRAMEWORK_PATH)Afficheur.cpp $(FRAMEWORK_PATH)Afficheur.hpp
	$(CC) -c -o $@ $< $(CFLAGS)


Jeu.o: $(FRAMEWORK_PATH)Jeu.cpp $(FRAMEWORK_PATH)Jeu.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

Joueur.o: $(FRAMEWORK_PATH)Joueur.cpp $(FRAMEWORK_PATH)Joueur.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

JoueurIA.o: $(FRAMEWORK_PATH)JoueurIA.cpp $(FRAMEWORK_PATH)JoueurIA.hpp \
$(FRAMEWORK_PATH)Joueur.hpp $(FRAMEWORK_PATH)Strategie.hpp
	$(CC) -c -o $@ $< $(CFLAGS)

Strategie.o: $(FRAMEWORK_PATH)Strategie.cpp $(FRAMEWORK_PATH)Strategie.hpp \
$(FRAMEWORK_PATH)JoueurIA.hpp 
	$(CC) -c -o $@ $< $(CFLAGS)


#
# Netoyage
#

.PHONY : clean clear

clean:
	rm -f *.o

clear: clean
	rm -f $(LIB_TARGET)



