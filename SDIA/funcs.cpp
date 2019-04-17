#include <stack>
#include "tree.h"
using namespace std;

void add(tree **t, int x)
{
	if (!*t)
	{
		*t = new tree(x, NULL, NULL);
		return;
	}
	if (x < (*t)->data)
	{
		if ((*t)->left)
			add(&(*t)->left, x);
		else
			(*t)->left = new tree(x, NULL, NULL);
	}
	if (x > (*t)->data)
	{
		if ((*t)->right != NULL)
			add(&(*t)->right, x);
		else
			(*t)->right = new tree(x, NULL, NULL);
	}
}

void buildtree(tree **t)
{
	int num;
	FILE *f;
	fopen_s(&f, "f.txt", "r");
	while (fscanf_s(f, "%d", &num) != EOF)
	{
		add(t, num);
		printf_s("%d was put in tree\n", num);
	}
	fclose(f);
}

void directed(tree *t)
{
	stack <tree *> S;
	while (t) 
	{
		printf_s("%d\n", t->data);
		if (t->left && t->right)
		{
			S.push(t->right);
			t = t->left;
		}
		else
			if (!t->left && !t->right && !S.empty())
			{
				t = S.top();
				S.pop();
			}
			else
				if (t->left)
					t = t->left;
				else t = t->right;
	}
}

void postorder1(tree *t)
{
	stack <tree *> S;
	bool toleft = true;
	tree *lastn = t;
	if (t)
	{
		S.push(lastn);
		while (!empty(S))
		{
			if (toleft)
			{
				while (lastn->left)
				{
					S.push(lastn);
					lastn = lastn->left;
				}
			}
			printf_s("%d\n", lastn->data);
			if (lastn->right)
			{
				lastn = lastn->right;
				toleft = true;
			}
			else
			{
				lastn = S.top();
				S.pop();
				toleft = false;
			}
		}
	}
}

void postorder2(tree *t)
{
	stack <tree *> S;
	tree *lastn = NULL;
	tree *topn = NULL;
	S.push(t);
	t = t->left;
	while (!empty(S))
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