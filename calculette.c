#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "analyse_syntaxique.h"
#include "ast_parcours.h"

  //resultat de séquence

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Erreur : Nombre d'arguments incorrect\n");
        return 1;
    }

    Ast arbre = NULL; // Pas besoin d'allouer de la mémoire ici, la création se fera dans la fonction analyser
    analyser(argv[1], &arbre);

    if (arbre != NULL) {
        printf("Pas d'erreur syntaxique\n");

        // Utilisez la fonction d'évaluation ici si nécessaire
        int resultat = evaluation(arbre);
        printf("Résultat : %d\n", resultat);

        // Affiche l'arbre
        afficher_ast(arbre);
        printf("\n");
        
    }

    return 0;
}

