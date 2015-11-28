


# Compilateur
CC=g++
CFLAGS=-Wall -Wextra --std=c++11 -g

# Objets 
SRC=main.cpp
OBJS=$(SRC:.cpp=.o)


# Executable
EXE=test

# Bibliothèque
FRAMEWORK_PATH=../framework/
LIB_TARGET=../libDiderot.a


all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIB_TARGET) $(CFLAGS)


#
# Objet principal
#

main.o: main.cpp
	$(CC) -c -o $@ $< $(CFLAGS)


#
# Netoyage
#

.PHONY : clean clear

clean:
	rm -f *.o

clear: clean
	rm -f $(EXE)

