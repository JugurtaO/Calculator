




##############################################################
# liste des fichiers source
SRC = calculette.c analyse_lexicale.c analyse_syntaxique.c ast_construction.c ast_parcours.c  lecture_caracteres.c 
#SRC = $(wildcard *.c)

# liste des fichiers .o et des dependances (mis dans le repertoire build/)
OBJ = $(addprefix build/,$(SRC:.c=.o))
DEP = $(addprefix build/,$(SRC:.c=.d))

# nom du compilateur
CC = gcc

# nom de l'executable
EXE = calculette 

# flags de compilation (CFLAGS) et d'edition de liens (LDFLAGS)
CFLAGS +=   -MMD -g -O2
LDFLAGS= #-lm

# regle principale: generer l'executable
all: $(OBJ)
	$(CC) -o $(EXE) $^ $(LDFLAGS)

# regle generique pour produire un fichier .o a partir d'un fichier .c
build/%.o: %.c
	@mkdir -p build
	$(CC) $(CFLAGS) -o $@ -c $<

# regle generique pour faire du nettoyage
clean:
	rm -rf build core *.gch

# inclusion automatique du fichier de dependances
-include $(DEP)















######
# essai_ast: ast_construction.o  ast_parcours.o  essai_ast.o  
# 	gcc -g -Wall -o essai_ast ast_construction.o  ast_parcours.o  essai_ast.o


# ast_construction.o: ast_construction.c ast_construction.h type_ast.h
# 	gcc -g -Wall -c ast_construction.c

# ast_parcours.o: ast_parcours.c ast_parcours.h type_ast.h
# 	gcc -g -Wall -c ast_parcours.c

# essai_ast.o: essai_ast.c  ast_construction.h  ast_parcours.h  type_ast.h
# 	gcc -g -Wall -c essai_ast.c




# clean:
# 	rm *.o essai_ast


###############"




