#include <stdlib.h>
#include <stdio.h>


struct memory_block{
	struct memory_block* previous;
	int data;
	struct memory_block* next;
};
struct memory_blo ck* head;

void visualize(void);
void insert(int data,int idx);
void delete(int idx);

int main(void){
	head = NULL;
	insert(0,0);
	insert(0,1);
	insert(2,2);
	visualize();
	insert(21,1);
	visualize();
	delete(0);
	visualize();
	return 0;
}
void insert(int data,int idx){

	struct memory_block* new_data = malloc(sizeof(struct memory_block));
	new_data->previous = NULL;
	new_data->next = NULL;
	new_data->data = data;
	if(idx==0){
		new_data->next = head;
		if (head != NULL) head->previous = new_data;
		head = new_data;
		return;
	}
	struct memory_block* prev_idx = head;
	for(int i=0;i<idx-1;i++){
		prev_idx =prev_idx->next;
	}
	struct memory_block* next_idx = prev_idx->next;
	
	new_data->previous = prev_idx;
	new_data->next = next_idx;
	
	prev_idx->next = new_data;
	if(next_idx!=NULL) next_idx->previous = new_data;
}

void delete(int idx){
	struct memory_block* prev_idx = head;
	if (idx == 0) {
		if (head != NULL) {
			struct memory_block* next_node = head->next;
			if (next_node != NULL) next_node->previous = NULL;
			free(head);
			head = next_node;
		}
		return;
	}
	for(int i=0;i<idx;i++){
		prev_idx = prev_idx->next;
	}
	struct memory_block* delete_idx = prev_idx->next;
	struct memory_block* next_idx = delete_idx->next;
	
	prev_idx->next = delete_idx->next;
	if(next_idx!=NULL) next_idx->previous = delete_idx->previous;
	free(delete_idx);
}
void visualize(void)
{
	const struct memory_block* temp = head; 
	while (temp != NULL)
	{
		printf("<- [prev:%p, data:%d, next:%p] -> ",temp->previous, temp->data, temp->next);
		temp = temp->next;
	}
	printf("\n");
}