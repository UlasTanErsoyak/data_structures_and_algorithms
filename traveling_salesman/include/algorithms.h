#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include "input.h"
struct node {
    int airport_id;
    int hops;
    struct node *next;
};
void enqueue(struct node **head, int airport_id, int hop);
struct node *dequeue(struct node *head);
int BFS(int **adj_matrix, int source, int target, int airport_count);
#endif