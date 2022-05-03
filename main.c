#include <stdio.h>


typedef struct Tree {
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree_t;


int main(){
    Tree_t * root = NULL;
    
    root = (Tree_t *) malloc(sizeof(Tree_t));

    // open file
    FILE * fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
}