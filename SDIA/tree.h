#pragma once

struct tree
{
	int data;
	tree *left, *right;
};

void add(tree **t, int x);

void buildtree(tree **t, FILE *f);

void postorder(tree *t);