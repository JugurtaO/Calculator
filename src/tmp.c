#include "analyse_syntaxique.h"
#include <stdio.h>

void analyser(char *fichier)
{
  demarrer(fichier);
  Etat_Automate_Ana etat = C_INIT;
  Lexeme Lex;

  int err;
  
  err = Rec_eag();

  if (err != 1)

    printf("Expression correcte ..\n");

  else
    printf("Expression incorrecte !! ..\n");
}
/*------------------------------------ récursive functions ------------------------------------------*/
/****************************************************************************************************/
int Rec_eag()
{
  int err = Rec_seq_terme();

  return err;
}
/********/
int Rec_seq_terme()
{
  
  int err;
  err = Rec_terme();
  if (err == 1)
    return 1;
  
  
  err = Rec_suite_seq_terme();
  if (err == 1)
    return 1;
  return 0;
}
/********/
int Rec_suite_seq_terme()
{
  int err;
  err = Rec_op1();
  afficher(lexeme_courant());
  printf("\n");
  if (err == 0)
  {

  
  
    err = Rec_terme();
    if (err == 1)
      return 1;


    err = Rec_suite_seq_terme();
    if (err == 1)
      return 1;
    return 0;
  }
  return 0;
}
/********/
int Rec_terme()
{
  int err = Rec_seq_facteur();
  
  return err;
}
/********/
int Rec_seq_facteur()
{
  int err;
  err = Rec_facteur();
 
  if (err == 1)
    return 1;

  err = Rec_suite_seq_facteur();
  if (err == 1)
    return 1;
  return 0;
}
/********/
int Rec_suite_seq_facteur()
{
  int err;
  err = Rec_op2();


  if (err == 0)
  {
  
  
    err = Rec_facteur();
    if (err == 1)
      return 1;

    err = Rec_suite_seq_facteur();
    if (err == 1)
      return 1;

    return 0;
  }
  // else
  //   return 0;

  
}
/********/

int Rec_facteur()
{
  int err;
   afficher(lexeme_courant());
  printf("\n");
  switch (lexeme_courant().nature)
  {
  case ENTIER:
    avancer();
    return 0;

    break;
  case PARO:

    avancer();
   
    err = Rec_eag();
    if (err == 1)
      return 1;
      

    afficher(lexeme_courant());

    if (lexeme_courant().nature == PARF)
    {
      avancer();
      return 0;
    }

    else
      return 1;

    break;
  default:
    return 1;
    break;
  }
}
/********/
int Rec_op1()
{
  afficher(lexeme_courant());
  printf("\n");
  switch (lexeme_courant().nature)
  {
  case PLUS:
  case MOINS:
    avancer();
    return 0; 
    break;

  default:
    return 1;
    break;
  }
}
/********/
int Rec_op2()
{
  afficher(lexeme_courant());
  printf("\n");
  switch (lexeme_courant().nature)
  {
  case MUL:
    avancer();
    return 0;
    break;

  default:
    return 1;
    break;
  }
}
