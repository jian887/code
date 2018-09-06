#include<stdio.h>
#include<malloc.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

typedef NODE* graph;

