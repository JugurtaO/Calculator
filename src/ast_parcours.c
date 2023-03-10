#include <stdio.h>
#include "../headers/type_ast.h"

void aff_operateur(TypeOperateur op){
	switch (op) {
		case N_PLUS:
			printf("+") ;
			break;
		case N_MOINS:
			printf("-") ;
			break;
		case N_MUL:
			printf("*") ;
			break;
		case N_DIV:
			printf("/") ;
			break;
	} 
}

void AfficherAST(Ast expr) {
	switch (expr->nature) {
               case OPERATION:
                        printf("(");
                        AfficherAST(expr->gauche);
                        aff_operateur(expr->operateur) ;
                        AfficherAST(expr->droite);
                        printf(")");
			break ;
               case VALEUR:
                  	printf("%d", expr->valeur);
			break ;
	}
}

int evaluation(Ast expr) {
      int vg, vd;
	  switch (expr->nature) {
	  case VALEUR:
	  	return expr->valeur;
		break;
	  case OPERATION:
	  	vg=evaluation(expr->gauche);
		vd=evaluation(expr->droite);
		switch (expr->operateur)
		{
		case N_PLUS:
			return vg +vd;
			break;
		case N_MOINS:
			return vg -vd;
			break;
		case N_MUL:
			return vg *vd;
			break;
		case N_DIV:
			if(vd==0){
				printf("Attention Division par ZÉRO !!");
				return -1;
			}
			return vg / vd;
			break;
		default:
			break;
		}
	  
	  default:
		break;
	  }
      return -1 ;
}

