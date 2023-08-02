#include <stdlib.h>
#include <stdio.h>

struct block{
	struct block* left;
	int data;
	struct block* right;
};

struct block* get_new_block(int data);
struct block* search(struct block* root, int data);
struct block* insert(struct block* new_block,int data);

int main(void){
    struct block* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 6);
    insert(root, 80);
 

    int key = 6;
 
    if (search(root, key) == NULL)
        printf("%d not found\n", key);
    else
        printf("%d found\n", key);
}

struct block* get_new_block(int data)
{
    struct block* temp = (struct block*)malloc(sizeof(struct block));
    temp->data = data;
    temp->left = NULL;
	temp->right = NULL;
    return temp;
}

struct block* search(struct block* root, int data)
{
    if (root == NULL || root->data == data)
        return root;
 
    if (root->data < data)
        return search(root->right, data);
 
    return search(root->left, data);
}
struct block* insert(struct block* new_block,int data){
	    if (new_block == NULL){
			return get_new_block(data);	
		} 
		
		if (data <= new_block->data){
			 new_block->left = insert(new_block->left, data);
		 }
        
		else if (data > new_block->data){
			new_block->right = insert(new_block->right, data);
		}
        return new_block;
		
}
