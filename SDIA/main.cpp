#include <stdio.h> 
#include <conio.h> 
#include <stack>
#include "tree.h"

enum Comands { CMD_DIRECTED = 1, CMD_POST1, CMD_POST2, CMD_EXIT };

int main()
{
	int num, exitFlag = 0, n;
	tree *t = NULL;
	buildtree(&t);
	printf_s("Tree from t.txt was successfully built.\nType a number: ");
	scanf_s("%d", &num);
	add(&t, num);
	instructions();
	while (!exitFlag)
	{
		printf("Enter the command number: ");
		if (!scanf_s("%d", &n))
		{
			printf_s("Error");
			return 0;
		}
		switch (n)
		{
			printf_s("Final version of tree:\n");
		case CMD_DIRECTED:
			directed(t);
			break;
		case CMD_POST1:
			postorder1(t);
			break;
		case CMD_POST2:
			postorder2(t);
			break;
		case CMD_EXIT:
			exitFlag = 1;
			break;
		default:
			printf_s("Invalid choise.\n");
			break;
		}
	}
	return 0;
}