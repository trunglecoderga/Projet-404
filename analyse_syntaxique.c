#include <string.h>
#include <stdlib.h> 
#include <stdio.h> 

#include "analyse_syntaxique.h"


void Rec_facteur(Ast *resultat) {
    switch (lexeme_courant().nature) {
    case ENTIER:
        *resultat = creer_valeur(lexeme_courant().valeur);
        avancer();
        if(lexeme_courant().nature == ENTIER){
            printf("erreur syntaxique\n");
            exit(1);
        }
        break;
    case PARO:
        avancer();
        Rec_eag(resultat);
        if (lexeme_courant().nature == PARF) {
            avancer();
        } else {
            printf("Erreur: Parenthèse fermante manquante\n");
            exit(1);
        }
        break;
    case MOINS:
    printf("rer");
      avancer();
      Ast A1;
      Rec_facteur(&A1);
    *resultat = creer_op_unaire(U_MOINS,A1);
    break;
    default:
        printf("Erreur: Facteur invalide\n");
        exit(1);
        break;
    }
}

void Rec_terme(Ast *resultat)
{
    Rec_seq_facteur(resultat);
}

void Rec_suite_seq_terme(Ast donnee, Ast *resultat) {
    TypeOperateur Op;
    switch (lexeme_courant().nature) {
    case PLUS:
    case MOINS:
        Rec_op1(&Op); 
        Ast Ad;
        Rec_terme(&Ad);
        *resultat = creer_operation(Op, donnee, Ad);
        Rec_suite_seq_terme(*resultat, resultat);
        break;
    default:
        *resultat = donnee;
        break;
    }
}

void Rec_seq_terme(Ast* resultat) {
    Ast A1;
    Rec_terme(&A1);
    Rec_suite_seq_terme(A1, resultat);
}

void Rec_eag(Ast *resultat)
{
    Rec_seq_terme(resultat);
}



void Rec_suite_seq_facteur(Ast donnee, Ast *resultat) {
    TypeOperateur Op;
    switch (lexeme_courant().nature) {
    case MUL:
    case DIV:
        Rec_op2(&Op);
        Ast Ad;
        Rec_facteur(&Ad);
        *resultat = creer_operation(Op, donnee, Ad);
        Rec_suite_seq_facteur(*resultat, resultat);
        break;
    default:
        *resultat = donnee;
        break;
    }
}


void Rec_seq_facteur(Ast *resultat) {
    Ast A1;
    Rec_facteur(&A1);
    Rec_suite_seq_facteur(A1, resultat);
}


void Rec_op1(TypeOperateur *Op)
{
    switch (lexeme_courant().nature)
    {
    case PLUS:
        *Op = N_PLUS;
        avancer();
        break;
    case MOINS:
       * Op = N_MOINS;
        avancer();
        break;
    default:
        printf("erreur\n");
        exit(0);
        break;
    }
}

void Rec_op2(TypeOperateur *Op)
{
    switch (lexeme_courant().nature)
    {
    case MUL:
        *Op = N_MUL;
        avancer();
        break;
    case DIV:
        *Op = N_DIV;
        avancer();
        break;
    default:
        printf("erreur\n");
        exit(0);
        break;
    }
}

void analyser(char *fichier, Ast *arbre)
{
    demarrer(fichier);   // demarre analyse lexical
    while (! fin_de_sequence())
    {
        Rec_eag(arbre);
    }  
    
    arreter();

}
