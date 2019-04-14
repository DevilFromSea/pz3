#include <stdio.h> 
#include <conio.h> 
#include <stack>
#include "tree.h"

int main()
{
	int num;
	FILE *f;
	tree *t = NULL;
	fopen_s(&f, "f.txt", "r");
	buildtree(&t, f);
	printf_s("Tree from t.txt was successfully built.\nType a number: ");
	scanf_s("%d", &num);
	add(&t, num);
	printf_s("Final version of tree:\n");
	postorder(t);
	system("pause");
}

