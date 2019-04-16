#pragma once

struct tree
{
	int data;
	tree *left, *right;
};

void add(tree **t, int x);

void buildtree(tree **t);

void directed(tree *t);

void postorder1(tree *t);

void postorder2(tree *t);

void instructions();