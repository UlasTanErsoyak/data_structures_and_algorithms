#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* left;
	struct node* right;
};

struct queue{
	struct node* data; 
	struct queue* next;
};

struct node* root = NULL;
struct queue* queue_head = NULL;
struct queue* queue_tail = NULL;

struct node* pop_queue();
void push_queue(struct node* data);
void insert(int data);
void traverse_tree();

int main(){

    insert(8);
    insert(3);
    insert(10);
    insert(1);
    insert(6);
    insert(14);
    insert(4);
    insert(7);
    insert(13);

    printf("levle order traversal: ");
    traverse_tree();
    printf("\n");
	return 0;
}

// queue functions
void push_queue(struct node* data){
	struct queue* new_queue_element = malloc(sizeof(struct queue));
	new_queue_element->next = NULL;
	new_queue_element->data = data;
	if(queue_head == NULL){
		queue_head = new_queue_element;
		queue_tail= new_queue_element;
	}
	else{
		queue_tail->next = new_queue_element;
		queue_tail = new_queue_element;
	}
}
struct node* pop_queue(){
	if(queue_head==NULL) return NULL;
	struct queue* temp = queue_head;
	queue_head = queue_head->next;
	struct node* data = temp->data;
	free(temp);
	return data;
}

// bst functions
void insert(int data){
	struct node* new_node = malloc(sizeof(struct node));
	new_node->left = new_node->right = NULL;
	new_node->data = data;
	if(root == NULL){
		root = new_node;
	}
	else{
		struct node* current = root;
		while(1){
			if (data <= current->data){
				if(current->left ==NULL){
					current->left = new_node;
					return;
				}
				current = current->left;
			}
			else{
				if(current->right ==NULL){
					current->right = new_node;
					return;
				}
				current = current->right;
			}
		}
	}
}

void traverse_tree(){
	if(root ==NULL) return;
	
	push_queue(root);
	
	while(queue_head!=NULL){
		struct node* current = pop_queue();
		printf("current data->%d\n",current->data);
		if(current->left!=NULL){
			push_queue(current->left);
		}
		if(current->right!=NULL){
			push_queue(current->right);
		}
	}
}