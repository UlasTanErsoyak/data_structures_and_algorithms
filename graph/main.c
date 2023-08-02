#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
struct node{
    int data;
    struct node* next;
};

struct node* adjacency_list[MAX_VERTICES];

int check(int data);
void add_vertex(int data);
void add_edge(int source,int destination);
void print_graph();
int main(void){
    add_vertex(1);
    add_vertex(2);
    add_vertex(3);
    add_edge(1,2);
    add_edge(1,2);
    add_edge(3,2);
    print_graph();

    return 0;
}
int check(int data){
    int len = sizeof(adjacency_list)/sizeof(adjacency_list[0]);
    for(int i=0;i<len;i++){
        if(adjacency_list[i]!=NULL && data==adjacency_list[i]->data){
            return 0;
        }
    }
    return 1;

}

void add_vertex(int data){

    if(check(data)==0){
        printf("%d is already in graph\n",data);
        return;
    } 
    int len = sizeof(adjacency_list)/sizeof(adjacency_list[0]);

    for(int i=0;i<len;i++){
        if(adjacency_list[i]==NULL){
            adjacency_list[i] = malloc(sizeof(struct node));
            adjacency_list[i]->data=data;
            adjacency_list[i]->next=NULL;       
            printf("added %d to the graph\n",data);
            return;
        }
    }
}
void add_edge(int source,int destination){
    if(check(source)==1){
        printf("source isnt a valid vertex\n");
        return;
    }
    if(check(destination)==1){
        printf("destination isnt a valid vertex\n");
        return;
    }

    int len = sizeof(adjacency_list)/sizeof(adjacency_list[0]);
    for(int i=0;i<len;i++){
        if(adjacency_list[i]!=NULL && source==adjacency_list[i]->data){
            struct node* current = adjacency_list[i];
            while(current->next !=NULL){
                current = current->next;
            }
            current->next = malloc(sizeof(struct node));
            current->next->data = destination;
            current->next->next = NULL;
        }        
    }
    for(int i=0;i<len;i++){
        if(adjacency_list[i]!=NULL && destination==adjacency_list[i]->data){
            struct node* current = adjacency_list[i];
            while(current->next !=NULL){
                current = current->next;
            }
            current->next = malloc(sizeof(struct node));
            current->next->data = source;
            current->next->next = NULL;
        }        
    }
    printf("added a connection between %d and %d \n",source,destination);
}

void print_graph() {
    int len = sizeof(adjacency_list) / sizeof(adjacency_list[0]);
    for (int i = 0; i < len; i++) {
        if (adjacency_list[i] != NULL) {
            struct node* current = adjacency_list[i];
            printf("Vertex", current->data);
            while (current != NULL) {
                printf(" %d", current->data);
                current = current->next;
            }
            printf("\n");
        }
    }
}
