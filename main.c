#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree_t;


void printTree(Tree_t *tree) {
    if (tree == NULL) {
        return;
    }
    printf("%d ", tree->value);
    printTree(tree->left);
    printTree(tree->right);
}


int main(){
    Tree_t * root = NULL;
    FILE * fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // while file not ended read values
    int value;
    while (fscanf(fp, "%d", &value) != EOF) {
        Tree_t * new_node = (Tree_t *) malloc(sizeof(Tree_t));
        new_node->value = value;
        new_node->left = NULL;
        new_node->right = NULL;

        // if root is empty
        if (root == NULL) {
            root = new_node;
        } else {
            Tree_t * current = root;
            while (current != NULL) {
                if (current->value > value) {
                    if (current->left == NULL) {
                        current->left = new_node;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == NULL) {
                        current->right = new_node;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }

    printTree(root);



}