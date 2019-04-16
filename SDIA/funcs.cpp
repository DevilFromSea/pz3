#include <stack>
#include "tree.h"
using namespace std;

void add(tree **t, int x)  
{
	if (!*t)             
	{
		*t = new tree;              
		(*t)->data = x;                  
		(*t)->left = NULL;
		(*t)->right = NULL;  
		return;
	}
	if (x < (*t)->data)   
	{
		if ((*t)->left) 
			add(&(*t)->left, x); 
		else          
		{
			(*t)->left = new tree;              
			(*t)->left->left = NULL; 
			(*t)->left->right = NULL; 
			(*t)->left->data = x;                   
		}
	}
	if (x > (*t)->data)             
	{
		if ((*t)->right != NULL) 
			add(&(*t)->right, x);
		else 
		{
			(*t)->right = new tree; 
			(*t)->right->left = NULL; 
			(*t)->right->right = NULL;
			(*t)->right->data = x;
		}
	}
}

void buildtree(tree **t)
{
	int num;
	FILE *f;
	fopen_s(&f, "f.txt", "r");
	while (fscanf_s(f, "%d", &num) != EOF && num != 0)
	{
		add(t, num);
		printf_s("%d was put in tree\n", num);
	}
	fclose(f);
}

void directed(tree *t)
{

}

void postorder1(tree *t)
{

}

void postorder2(tree *t)
{
	stack <tree *> S;
	tree *lastn = NULL;
	tree *topn = NULL;
	while (!empty(S) || t)
	{
		if (t)
		{
			S.push(t);
			t = t->left;
		}
		else
		{
			topn = S.top();
			if (topn->right && lastn != topn->right)
			{
				t = topn->right;
			}
			else
			{
				S.pop();
				printf_s("%d\n", topn->data);
				lastn = topn;
			}
		}
	}
}

void instructions()
{
	printf_s("How would you like to print the tree?\n"
			 "1)Directed order\n"
			 "2)Postorder (left child -> root -> right child)\n"
			 "3)Postorder (left child -> right child -> root)\n"
			 "4)Exit\n");
}