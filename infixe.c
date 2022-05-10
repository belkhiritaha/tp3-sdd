#include <stdio.h>
#include<stdlib.h>

//Mettre en lien avec le gestionnaire de pile

void infixe(tree_t* a) {
    tree_t* cour = *a;
    Pile *pile = initPile();
    int end = 0;

    while (!end){

        while (cour!=NULL){
            Empiler(&pile, cour);
            cour = cour -> Tree *left;
        }

        if (!pile){
            cour = Depiler(&pile);
            printf("%d", cour->value);
            cour = cour -> Tree *right;
        }
        else{
            end = 1;
        }
    }
}

//chien