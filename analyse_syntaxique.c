#include "analyse_syntaxique.h"
#include <stdio.h>
#include "ast_construction.h"
#include "ast_parcours.h"
#include <stdint.h>
#include <stdlib.h>

int analyser(char *nom_fichier, Ast *arbre)
{
  demarrer(nom_fichier);

  int err = 0;

  err = Rec_eag(arbre);
  if (lexeme_courant().nature != FIN_SEQUENCE)
    err = 1;
  printf("Err final = %d\n", err);
  if (err == 0){
     printf("Expression correcte ..\n");
    return 0;
  }

   

  else {
    printf("Expression incorrecte !! ..\n");
    return 1;
  }
    
}
/*------------------------------------ récursive functions ------------------------------------------*/
/****************************************************************************************************/
int Rec_eag(Ast *A)
{
  printf("inside eag : \n");
  int err = Rec_seq_terme(A);
  printf("inside eag after seq_terme:err = %d \n", err);
  if (err == 1)
    return 1;
  else
    return 0;
}
/********/
int Rec_seq_terme(Ast *A)
{
  Ast A1;
  printf("inside seq_terme : \n");

  int err = Rec_terme(&A1);
  printf("inside seq_terme after terme :err=%d \n", err);
  if (err == 1)
  {
    printf("Erreur in Rec_terme: \n");
    return 1;
  }
  err = Rec_suite_seq_terme(A1, A);
  printf("inside seq_terme after suite_seq_terme : err=%d\n", err);
  if (err == 1)
  {
    printf("Erreur in Rec_suite_seq_terme : \n");
    return 1;
  }
  return 0;
}
/********/
int Rec_suite_seq_terme(Ast Ag, Ast *A)
{
  Ast Ad;
  Ast A1;
  TypeOperateur Op;

  printf("inside suite_seq_terme : \n");
  switch (lexeme_courant().nature)
  {
  case PLUS:
  case MOINS:
    int err = Rec_op1(&Op);
    printf("inside suite_seq_terme after OP1: err=%d\n", err);
    if (err != 1)
    {
      err = Rec_terme(&Ad);
      printf("inside suite_seq_terme after terme:err=%d \n", err);
      if (err == 1)
      {
        printf("Erreur in Rec_terme l,53 : \n");
        return 1;
      }

         printf("************\n");
    AfficherAST(Ad);
    printf("\n");


    AfficherAST(Ag);
      printf("\n");
    printf("************\n");
      A1 = creer_operation(Op, Ag, Ad);
      AfficherAST(A1);
      err = Rec_suite_seq_terme(A1, A);
      printf("inside suite_seq_terme after suite_seq_terme :err=%d \n", err);
      if (err == 1)
      {
        printf("Erreur in Rec_suite_seq_terme l,60 : \n");
        return 1;
      }

      return 0;
    }

    break;

  default:
    printf("J'ai lu epsilone : \n");
    *A = Ag;
    break;
  }

 
}
/********/
int Rec_terme(Ast* A)
{
  printf("inside terme : \n");
  int err = Rec_seq_facteur(A);
  printf("inside terme after seq_facteur :err= %d \n", err);
  if (err == 1)
    return 1;
  else
    return 0;
}
/********/
int Rec_seq_facteur(Ast *A)
{
  Ast A1 ;
  printf("inside seq_facteur : \n");
  int err;
  err = Rec_facteur(&A1);
  printf("inside seq_facteur after facteur:err= %d \n", err);

  if (err == 1)
  {
    printf("Erreur in Rec_facteur l,83 : \n");
    return err;
  }
  err = Rec_suite_seq_facteur(A1, A);
  printf("inside seq_facteur after suite_seq_facteur: err=%d \n", err);
  if (err == 1)
  {
    printf("Erreur in Rec_suite_seq_facteur l,90 : \n");
    return 1;
  }
  return 0;
}
/********/
int Rec_suite_seq_facteur(Ast Ag, Ast *A)
{
  Ast Ad;
  Ast A1;
  TypeOperateur Op;
  printf("inside suite_seq_facteur : \n");
  int err;
  err = Rec_op2(&Op);
  printf("inside suite_seq_facteur after OP2:err=%d\n", err);
  if (err != 1)
  {
    err = Rec_facteur(&Ad);

 
    printf("inside suite_seq_facteur after facteur :err=%d\n", err);
    if (err == 1)
    {
      printf("Erreur in Rec_facteur in suite_seq_facteur : \n");
      return 1;
    }
    A1 = creer_operation(Op, Ag, Ad);
    AfficherAST(A1);
     printf("\n");
    printf("\n");
    err = Rec_suite_seq_facteur(A1, A);
    printf("inside suite_seq_facteur after_suite_seq_facteur :err=%d \n", err);
    if (err == 1)
    {
      printf("Erreur in Rec_suite_seq_facteur l,115 : \n");
      return 1;
    }
    return 0;
  }
  printf("j'ai lu epsilone\n");
  *A = Ag;
}
/********/

int Rec_facteur(Ast *A)
{

  printf("inside Facteur : \n");
  afficher(lexeme_courant());
  printf("\n");
  switch (lexeme_courant().nature)
  {
  case ENTIER:
    *A = creer_valeur(lexeme_courant().valeur);
    AfficherAST(*A);
     printf("\n");
    avancer();
    printf("Sortie case entier\n");

    break;
  case PARO:

    avancer();

    int err = Rec_eag(A);
    printf("inside Facteur after eag :err=%d \n", err);
    if (err == 1)
    {
      printf("Erreur in Rec_eag l,144 : \n");
      return 1;
    }

    if (lexeme_courant().nature == PARF)
    {
      avancer();
      // return 0;
    }

    else
    {
      printf("Error from not PARF\n");
      return 1;
    }
    break;
  default:
    printf("error from default\n");
    return 1;
    break;
  }
}
/********/
int Rec_op1(TypeOperateur *Op)
{
  printf("inside OP1 : \n");
  afficher(lexeme_courant());
  printf("\n");
  switch (lexeme_courant().nature)
  {
  case PLUS:
    *Op = N_PLUS;
    avancer();
    break;
  case MOINS:
    *Op = N_MOINS;
    avancer();
    // return 0;
    break;

  default:
    return 1;
    break;
  }
}
/********/
int Rec_op2(TypeOperateur *Op)
{
  printf("inside OP2 : \n");
  afficher(lexeme_courant());
  printf("\n");
  switch (lexeme_courant().nature)
  {
  case MUL:
    *Op = N_MUL;
    avancer();
    break;
  case DIV:
    *Op = N_DIV;
    avancer();

    // return 0;
    break;

  default:
    return 1;
    break;
  }
}
