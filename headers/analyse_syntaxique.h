#include "analyse_lexicale.h"
#include "lecture_caracteres.h"
#include "type_ast.h"
#include <stdio.h>
#define MAX_SIZE 100
typedef enum {C_INIT, C_ENTIER, C_FIN, C_PARO,C_PARF,C_ERROR, C_OPARATEUR} Etat_Automate_Ana ;



int Rec_eag(Ast * A);
int Rec_seq_terme(Ast* A);
int Rec_suite_seq_terme(Ast a, Ast *A);
int Rec_terme(Ast *A);
int Rec_suite_seq_facteur(Ast ag, Ast *A);
int Rec_seq_facteur(Ast *A);
int Rec_facteur(Ast *A);
int Rec_op1(TypeOperateur *op);
int Rec_op2(TypeOperateur * op );

int analyser(char *fichier,Ast *arbre);
