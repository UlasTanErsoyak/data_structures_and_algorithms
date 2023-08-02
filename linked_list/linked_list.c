#include <stdlib.h>
#include <stdio.h>

struct memory_block
{
	int data;
	struct memory_block* next;
};

struct memory_block* head;

void visualize(void);
void insert_at_start(int data);
void insert_at_idx(int data, int idx);
void delete_at_idx(int idx);

int main(void)
{
	head = NULL;
	while(true){
		printf("1)insert\n2)delete\n3)visualize\n4)exit");
	}#include <stdlib.h>
#include <stdio.h>

struct memory_block
{
	int data;
	struct memory_block* next;
};

struct memory_block* head;

void visualize(void);
void insert_at_start(int data);
void insert_at_idx(int data, int idx);
void delete_at_idx(int idx);

int main(void)
{
	head = NULL;
	delete_at_idx(2);
	insert_at_idx(909, 0);
	insert_at_idx(22, 1);
	visualize();
	insert_at_idx(23, 0);
	visualize();
	delete_at_idx(1);
	//visualize();

	return 0;
}

void insert_at_start(int data)
{
	struct memory_block* temp_block = malloc(sizeof(struct memory_block));
	temp_block->data = data;
	temp_block->next = head;
	head = temp_block;
}
void insert_at_idx(int data,int idx)
{
	struct memory_block* new_data = malloc(sizeof(struct memory_block));
	new_data->data = data;
	new_data->next = NULL;
	if(idx == 0)
	{
		new_data->next = head;
		head = new_data;
		return;
	}
	struct memory_block* block_at_idx = head;
	for(int i=0;i<idx-1;i++)
	{
		block_at_idx = block_at_idx->next;
	}
	new_data->next = block_at_idx->next;
	block_at_idx->next = new_data;
}
void delete_at_idx(int idx)
{
	if(head == NULL)
	{
		printf("cant delete %dth index, list is empty\n",idx);
		return;
	}

	struct memory_block* prev_idx = head;
	if (idx == 0)
	{
		head = prev_idx->next;
		free(prev_idx);
		return;
	}
	for (int i = 0; i < idx-1; i++)
	{
		prev_idx = prev_idx->next;
	}
	struct memory_block* delete_idx = prev_idx->next;
	prev_idx->next = delete_idx->next;
	free(delete_idx);

}
void visualize(void)
{
	const struct memory_block* temp = head; 
	while (temp != NULL)
	{
		printf("[current:%p, data:%d, next:%p] -> ",temp, temp->data, temp->next);
		temp = temp->next;
	}
	printf("\n");
}


	return 0;
}

void insert_at_start(int data)
{
	struct memory_block* temp_block = malloc(sizeof(struct memory_block));
	temp_block->data = data;
	temp_block->next = head;
	head = temp_block;
}

void insert_at_idx(int data, int idx)
{
	struct memory_block* new_data = malloc(sizeof(struct memory_block));
	new_data->data = data;
	new_data->next = NULL;
	if (idx == 0)
	{
		new_data->next = head;
		head = new_data;
		return;
	}
	struct memory_block* block_at_idx = head;
	for (int i = 0; i < idx - 1; i++)
	{
		block_at_idx = block_at_idx->next;
	}
	new_data->next = block_at_idx->next;
	block_at_idx->next = new_data;
}

void delete_at_idx(int idx)
{
	if (head == NULL)
	{
		printf("cant delete %dth index, list is empty\n", idx);
		return;
	}
	struct memory_block* prev_idx = head;
	if (idx == 0)
	{
		head = prev_idx->next;
		free(prev_idx);
		return;
	}
	for (int i = 0; i < idx - 1; i++)
	{
		prev_idx = prev_idx->next;
	}
	struct memory_block* delete_idx = prev_idx->next;
	prev_idx->next = delete_idx->next;
	free(delete_idx);
}

void visualize(void)
{
	const struct memory_block* temp = head;
	while (temp != NULL)
	{
		printf("[current:%p, data:%d, next:%p] -> ", temp, temp->data, temp->next);
		temp = temp->next;
	}
	printf("\n");
}
