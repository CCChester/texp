//texp.h

#include <stdlib.h>
#include <stdbool.h>

struct enode {
  char op;  // one of '+', '-', '/', '*' [invalid if leaf node]
  int arg;  // one of 0..9 [invalid if non-leaf node]
  struct enode *left;  // NULL if leaf node
  struct enode *right; // NULL if leaf node
};


// newnode() returns a new enode
//   PRE: true
//   POST: returnings a newly allocated enode, 
//         where left and right are NULL, and op & arg are not initialized
//   TIME: O(1)
struct enode *newnode(void);


// destroy_tree(t) destroys t and all subtrees
//   PRE: t is not NULL
//   POST: frees all the memory allocated for t and all subtrees.
//   TIME: O(n) where n in the number of nodes in tree t.
void destroy_tree(struct enode *t);


// eval(t) evaluates the arithmetic expression stored in t
//   PRE: t is a valid arithmetic expression
//   POST: returns the final value of the expression represented by t
//   TIME: O(n) where n in the number of nodes in t.
int eval(struct enode *t);


// build_tree(c) produces an expression tree for the expression in c
//   PRE: c is a valid fully parenthesized expression, null terminated
//   POST: returns a new tree representing the expression c
//   TIME: O(n) where n is the length of c
struct enode *build_tree(char c[]);


//  traverse_inorder(t) prints the fully parenthesized expression stored in t
//  PRE: t is a valid tree 
//  POST: prints the fully parenthesized expression stored in tree t ending with \n.
//  TIME: O(n) where n in the number of nodes in tree t.
void traverse_inorder(struct enode *t);
