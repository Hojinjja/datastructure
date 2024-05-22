#include <stdlib.h>
#include <stdio.h>
#include "bintree.h"

bintree_t * 
bintree_create (char data) 
{
	node_t * root ;
	root = (node_t *) malloc(sizeof(node_t)) ;
	root->data = data ;
	root->left= NULL ;
	root->right = NULL ; 
	return root ;
}

bintree_t *
bintree_add_left (bintree_t * parent, bintree_t * child)
{
	parent->left = child;
}

bintree_t *
bintree_add_right (bintree_t * parent, bintree_t * child)
{
	parent->right = child;
}

bintree_t *
bintree_search (bintree_t * t, char key)
{
	if (t->data ==key)
		return t; 

	bintree_t *r;
	r = bintree_search(r->left,key);

	if(r != NULL){
		return r;
	}
	r= bintree_search(r->right,key);
		return r;
	/*TODO*/
}

int
bintree_is_ancestor (bintree_t * t1/*parent*/, bintree_t * t2 /*child*/)
{
	if(t2 == t1->left || t2 == t1->right){
		return 1; 
	}

	if(t1->left){
		if (bintree_is_ancestor(t1->left,t2)){
			return 1;
		}
	}
	if(t1->right){
		if (bintree_is_ancestor(t1->right,t2)){
			return 1;
		}
	}


// 	if t1 is the ancestor of t2 
// 		return 1;
// 	return 0;
	/*TODO*/
}

void
bintree_delete (bintree_t * t)
{
	/*TODO*/
	if(t->left)
		bintree_delete(t->left);
	if(t->left)
		bintree_delete(t->right);
	free(t);
}


int
bintree_height(bintree_t * t) 
{
	/*TODO*/
	int max_height = 0 ;

	bintree_t * st ; 

	if (t->left){
		int height;
		height = bintree_height(t->left);
		if(max_height<height){
			max_height = height;
		}
	}
	if (t->right){
		int height;
		height = bintree_height(t->right);
		if(max_height<height){
			max_height = height;
		}
	}
}


void
bintree_print (bintree_t * t)
{
	/*TODO*/
	printf("%c",t->data);		// V
	printf("(");
	if(t->left){
		bintree_print(t->left); // L
	}
	printf(" ,");
	if(t->right){
		bintree_print(t->right); // R
	}
	printf(")");
}


// LEVEL ORDER TRAVERSAL �� ��ͷ� © �� ����. 
