#include <stdlib.h>
#include <stdio.h>

struct memory_block{
	int data;
	struct memory_block* next;
};

struct memory_block* head = NULL;
struct memory_block* tail = NULL;

void push(int data);
void pop();
void peek();

int main(){
	
	peek();
	push(2);
	peek();
	push(30);
	peek();
	pop();
	peek();
	pop();
	peek();
	return 0;
}

void push(int data){
	struct memory_block* new_data = malloc(sizeof(struct memory_block));
	new_data->data = data;
	new_data->next = NULL;
	if(head==NULL){
		head=new_data;
		tail=new_data;
	}
	else{
		tail->next = new_data;
		tail = new_data;
	}
}

void pop(){
	if(head == NULL){
		printf("queue is empty\n");
	}
	else{
		struct memory_block* temp = head;
		head = head->next;
		free(temp);
	}
}
void peek(){
	if(head==NULL){
		printf("queue is empty\n");
	}
	else{
		printf("head: %d\n",head->data);
	}
}