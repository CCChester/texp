#include <stdio.h>
#include <assert.h>
#include "texp.h"

int main(void){ 
 	
 	struct enode *t1;
	char e1[100];
	for (int i=1; i<4; i++){
		scanf("%s", e1);
    	        t1=build_tree(e1);
		printf("%d\n",eval(t1));
		traverse_inorder(t1);
		destroy_tree(t1);
	}

	return 0;
} 

