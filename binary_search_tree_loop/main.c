#include <stdlib.h>
#include <stdio.h>

struct block {
	int data;
	struct block* left;
	struct block* right;
};

struct block* root = NULL;
void insert(int data);
void search(int data);
int main(void) {
	insert(50);
	insert(30);
	insert(40);
	insert(41);
	insert(39);
	search(39);
	return 0;
}
void search(int data) {
	struct block* current = root;
	while (current != NULL) {

		if (data == current->data) {
			printf("found %d", data);
			return;
		}
		else if (data < current->data) {
			current = current->left;
			continue;
		}
		else if (data > current->data) {
			current = current->right;
			continue;
		}
		printf("couldnt found %d", data);
	}
}
void insert(int data) {
	struct block* new_data = malloc(sizeof(struct block));
	new_data->left = new_data->right = NULL;
	new_data->data = data;

	if (root == NULL) {
		root = new_data;
		return;
	}

	struct block* current = root;
	while (1) {
		if (data <= current->data) {
			if (current->left == NULL){
				current->left = new_data;
				return;
			}
			current = current->left;
		}
		else {
			if (current->right == NULL) {
				current->right = new_data;
					return;
			}
			current = current->right;
		}
	}
}