
#include <stdio.h>
#include "type_ast.h"

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
			printf("/");
			break;
	} 
}

void afficher_ast(Ast expr) {
	switch (expr->nature) {
               case OPERATION:
                        printf("(");
                        afficher_ast(expr->gauche);
                        aff_operateur(expr->operateur) ;
                        afficher_ast(expr->droite);
                        printf(")");
			break ;
               case VALEUR:
                  	printf("%d", expr->valeur);
			break ;
			default:
			printf("test8");break;
	}
}

int evaluation(Ast expr) {
      // A COMPLETER !
	int Vg, Vd;
	switch (expr->nature)
	{
	case VALEUR:
		return expr->valeur;
		break;
	case OPERATION:
		Vg = evaluation(expr->gauche);
		Vd = evaluation(expr->droite);
		switch (expr->operateur)
		{
		case N_PLUS:
			return Vg + Vd;
			break;
		case N_MOINS:
			return Vg - Vd;
			break;
		case N_MUL:
			return Vg*Vd;
			break;
		case N_DIV:
			return Vg/Vd;
			break;
		default:
			break;
		}
	default:
		break;
	}
	return -1 ;
}

