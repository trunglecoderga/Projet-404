#include <stdlib.h>
#include <stdio.h> 

#include "type_ast.h"

Ast creer_operation(TypeOperateur opr , Ast opde_gauche , Ast opde_droit) 
{
      Ast expr ;
      expr = (Ast) malloc (sizeof(NoeudAst));
      expr->nature = OPERATION;
      expr->operateur = opr;
      if (opde_gauche == NULL || opde_droit == NULL) {
         printf("ERREUR_EXPRESSION\n") ;
	 exit(1) ;
      } else {
         expr->gauche = opde_gauche;
         expr->droite = opde_droit;
      } ;
      return expr ;
}

Ast creer_valeur(int val) { 
      Ast expr ;
      expr = (Ast) malloc (sizeof(NoeudAst));
      expr->nature = VALEUR;
      expr->valeur = val;
      return expr ;
}

Ast creer_op_unaire(TypeOperateur op,Ast a){
      Ast expr;
      expr = (Ast) malloc (sizeof(NoeudAst));
      expr->nature = OPERATION;
      expr ->operateur = op;
      if(a==NULL){
            printf("erreur \n");
            exit(1);      }
      else{
      expr->gauche = a;
      expr->droite = NULL;}

      return expr;

}
