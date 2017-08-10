//texp.c

#include "texp.h"
#include <stdio.h>
#include <assert.h>

//see texp.h for documentation
struct enode *newnode(void) { 
  struct enode *t=malloc(sizeof(struct enode)); 
  t->left=NULL; 
  t->right=NULL; 
  return t; 
}

//see texp.h for documentation
void destroy_tree(struct enode *t){
  if (NULL == t) {return;}
  destroy_tree(t->left);
  destroy_tree(t->right);
  free(t);
}

//YOUR IMPLEMENTATION STARTS HERE
int eval(struct enode *t){
    assert(t);
    int final = 0;
    if ((t->left == NULL) && (t->right == NULL)){
        return t->arg;
    }
    int l = eval(t->left);
    int r = eval(t->right);
    char s = t->op;
    if (s == '+'){
        final = l+r;
    }
    else if (s == '-'){
        final = l-r;
    }
    else if (s == '*'){
        final = l*r;
    }
    else if (s == '/'){
        final = l/r;
    }
    return final;
}

/* Helper_built(**s) produces an 
 * expression tree for the expression in s.
 *  PRE: True
 *  POST: returns a new tree 
 *        representing the expression s.
 */
struct enode *helper_built(char **s){
    struct enode *new = NULL;
    if (**s >= '0' && **s <= '9'){
        new = malloc(sizeof(struct enode));
        new->op = ' ';
        new->arg = **s - '0';
        new->left = NULL;
        new->right = NULL;
        (*s)++;
    }
    else {
        (*s)++;
        new = malloc(sizeof(struct enode));
        new->left = helper_built(s);
        new->op = **s;
        (*s)++;
        new->right = helper_built(s);
        (*s)++;
    }
    return new;
}

struct enode *build_tree(char c[]){
    return helper_built(&c);
}

/* helper_print(t) prints the fully
 * parenthesized expression stored in t.
 *  PRE: True
 *  POST: prints the fully parenthesized
 *        expression stored in tree t.
 */
void helper_print(struct enode *t){
    if ((t->left == NULL) && (t->right == NULL)){
        printf("%d", t->arg);
    }
    else{
    printf("(");
    helper_print(t->left);
    printf("%c",t->op);
    helper_print(t->right);
    printf(")");
    }
}

void traverse_inorder(struct enode *t){
   assert(t);
   helper_print(t);
   printf("\n");
}

