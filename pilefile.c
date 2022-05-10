#include <stdio.h>
#include <stdlib.h>

typedef struct pile
{
    int TailleMax;
    int *tab;
    int *deb;
    int *fin;
} pile_t;


typedef struct file
{
    int TailleMax;
    int *tab;
    int *deb;
    int *fin;
} file_t;


pile_t *initPile(int TailleMax)
{
    pile_t *ma_pile = calloc(1, sizeof(pile_t));
    ma_pile->TailleMax = TailleMax;
    ma_pile->tab = calloc(ma_pile->TailleMax, sizeof(int));
    ma_pile->deb = ma_pile->tab;
    ma_pile->fin = ma_pile->tab;
    return ma_pile;
}

int Empiler(pile_t *pile, int elt)
{
    if ( pile->fin - pile->deb < pile->TailleMax){
        for (int i= pile->fin - pile->tab ; i >= pile->deb - pile->tab; i--){
            pile->tab[i+1] = pile->tab[i];
        }
        *pile->deb = elt;
        pile->fin++;
        return 0; // SUCCES 
    }
    else {
        return 1; // FAILURE
    }
}


int Depiler(pile_t *pile){
    if (pile->deb != pile->fin){
        *pile->deb = 0;
        pile->deb++;
        return 0; // SUCCES
    }
    else {
        return 1; // FAILURE
    }
}

void PrintPile(pile_t *pile){
    for (int i = pile->deb - pile->tab; i < pile->fin - pile->tab; i++)
    {
        printf("%d\n", pile->tab[i]);
    }
}

int Enfiler(pile_t *pile, int elt)
{
    if ( pile->fin - pile->deb < pile->TailleMax){
        for (int i= pile->fin - pile->tab ; i >= pile->deb - pile->tab; i--){
            pile->tab[i+1] = pile->tab[i];
        }
        *pile->deb = elt;
        pile->fin++;
        return 0; // SUCCES 
    }
    else {
        return 1; // FAILURE
    }
}


int Defiler(pile_t *pile){
    int retour = 420;
    if (pile->deb != pile->fin){
        retour = *pile->fin;
        pile->fin--;
    }
    return retour;
}

void InverserPile(pile_t * pile){
	file_t file_tmp;
		
}
