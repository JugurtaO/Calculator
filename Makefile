CC=gcc
CFLAGS=-g -c     #-Wall
LDFLAGS=-g  -o    #-Wall

exe=calculette test_lexeme essai_ast

all:$(exe)


analyse_lexicale.o: analyse_lexicale.c analyse_lexicale.h lecture_caracteres.h

lecture_caracteres.o: lecture_caracteres.h lecture_caracteres.c

test_lexeme.o: analyse_lexicale.h

analyse_syntaxique.o:analyse_syntaxique.c  analyse_syntaxique.h analyse_lexicale.h lecture_caracteres.h  ast_construction.h

ast_construction.o: ast_construction.c ast_construction.h type_ast.h
ast_parcours.o: ast_parcours.c ast_parcours.h type_ast.h
essai_ast.o: essai_ast.c  ast_construction.h  ast_parcours.h  type_ast.h

calculette.o: calculette.c analyse_lexicale.h analyse_syntaxique.h lecture_caracteres.h ast_construction.h ast_parcours.h



%.o:%.c
	$(CC) $(CFLAGS) $<

essai_ast: ast_construction.o  ast_parcours.o  essai_ast.o  

test_lexeme: analyse_lexicale.o  lecture_caracteres.o  test_lexeme.o
	gcc -g -Wall -o test_lexeme analyse_lexicale.o  lecture_caracteres.o  test_lexeme.o

calculette: calculette.o analyse_syntaxique.o analyse_lexicale.o  lecture_caracteres.o ast_construction.o ast_parcours.o
	gcc -g -Wall -o calculette analyse_syntaxique.o  analyse_lexicale.o  lecture_caracteres.o  calculette.o ast_construction.o ast_parcours.o

%:%.o
	$(CC) $(LDFLAGS) $@ $^

clean:
	rm -f  *.o $(exe)




















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




