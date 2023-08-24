#include "../include/algorithms.h"
void enqueue(struct node **head, int airport_id, int hop){
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->airport_id = airport_id;
    new_node->hops = hop;
    new_node->next = NULL;
    if(*head == NULL){
        *head = new_node;
    }
    else{
        struct node *current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = new_node;
    }
}
struct node* dequeue(struct node *head){
    if(head == NULL){
        printf("[error][dequeue]->cant dequeue an empty queue");
        exit(-1);
    }
    struct node *new_head = head->next;
    free(head);
    return new_head;
}
int BFS(int **adj_matrix, int source, int target, int airport_count){
    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    head->hops = 0;
    head->airport_id = source;
    int *visited_airports = calloc(airport_count, sizeof(int));
    int i;
    while (head != NULL){
        int current_airport = head->airport_id;
        int current_hops = head->hops;
        if(current_airport == target){
            free(visited_airports);
            while(head != NULL){
                head = dequeue(head);
            }
            return current_hops;
        }
        head = dequeue(head);
        for(i=0;i<airport_count;i++){
            if(adj_matrix[current_airport][i] == 1 && !visited_airports[i]){
                visited_airports[i]=1;
                enqueue(&head,i,current_hops+1);
            }
        }
    }
    free(visited_airports);
    return -1;
}