#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct memory_block {
	int data;
	struct memory_block* next;
};

struct memory_block* head;

void push(int data);
void pop();
void visualize(void);

int main(void) {
	head = NULL;
	push(10);
	push(11);
	visualize();
	push(12);
	visualize();
	pop();
	visualize();
	return 0;
}
void push(int data) {

	struct memory_block* new_data = malloc(sizeof(struct memory_block));
	new_data->next = NULL;
	new_data->data = data;
	if (head == NULL) {
		head = new_data;
		return;
	}
	struct memory_block* prev_data = head;
	while (prev_data->next != NULL) {
		prev_data = prev_data->next;
	}
	prev_data->next = new_data;
}

void pop() {
	if (head == NULL) {
		printf("stack is already empty");
		return;
	}

	struct memory_block* prev_data = head;
	while (prev_data->next->next != NULL) {
		prev_data = prev_data->next;
	}
	free(prev_data->next);
	prev_data->next = NULL;
}
void visualize(void)
{
	const struct memory_block* temp = head;
	while (temp != NULL)
	{
		printf("[data:%d, next:%p] -> ",temp->data, temp->next);
		temp = temp->next;
	}
	printf("\n");
}
