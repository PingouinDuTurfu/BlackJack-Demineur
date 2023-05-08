#Emplacement des dossiers
srcdir = ./src/
bindir = ./bin/
docdir = ./doc/
savedir = ./save/

#Variables liées aux differentes commandes
CC = gcc -Wall
CP = cp
RM = rm -rf
TAR = tar czvf
DOXYGEN = doxygen

# Récupération des fichiers .c
SRC = $(wildcard $(srcdir)*.c)

# Récupération des fichiers .h
HEAD = $(wildcard $(srcdir)*.h)

# Liste des noms des fichiers .o
OBJ = $(subst $(srcdir), $(bindir), $(SRC:.c=.o))

# Nom de l'executable
PROG = $(bindir)prog

# Nom du repertoire courant pour la compression 
TARNAME = $(shell basename $(CURDIR))

# List des saves actuelles
SAVENAME = $(wildcard $(savedir)*)

# Récupération de la version de la save actuelle
SAVEVERSION = $(shell echo $(SAVENAME) | sed -e 's/save//g;s/\.//g;s/\///g' | tr ' ' '\n' | sort -n | tail -n 1)

all : ${PROG}

${PROG} : ${OBJ}
	${CC} $^ -o $@ -lm

$(bindir)%.o : $(srcdir)%.c
	${CC} -c $^ -o $@

.PHONY : save restore give clean run doxygen
save :
	mkdir $(savedir)save$$(($(SAVEVERSION)+1))/
	$(CP) $(SRC) $(HEAD) $(savedir)save$$(($(SAVEVERSION)+1))/

restore :
	$(RM) $(srcdir)*
	$(CP) $(savedir)save$(SAVEVERSION)/* $(srcdir)

give :
	make clean
	${TAR} ../$(TARNAME).tar.gz ../$(TARNAME)

clean :
	${RM} ${bindir}*
	${RM} ${docdir}*

run :
	$(PROG)

blackjack :
	gcc -Wall ./src/blackjack/*.c -o ./bin/blackjack

demineur :
	gcc -Wall ./src/demineur/*.c -o ./bin/demineur

runblackjack :
	./bin/blackjack

rundemineur :
	./bin/demineur

doxygenblackjack :
	${DOXYGEN} DoxyfileBlackjack

doxygendemineur :
	${DOXYGEN} DoxyfileDemineur
