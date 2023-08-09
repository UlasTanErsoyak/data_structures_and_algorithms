#include <stdlib.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
struct node{
    int data;
    int balance;
    struct node* parent;
    struct node* right;
    struct node* left;
};
int height(struct node* node) {
    if (node == NULL)
        return -1;
    return 1 + max(height(node->left), height(node->right));
}
void updateBalance(struct node* node) {
    if (node == NULL)
        return;
    node->balance = height(node->left) - height(node->right);
}
struct node* rotateRight(struct node* y) {
    struct node* x = y->left;
    struct node* T2 = x->right;
    x->right = y;
    y->left = T2;
    updateBalance(y);
    updateBalance(x);
    return x;
}
struct node* rotateLeft(struct node* x) {
    struct node* y = x->right;
    struct node* T2 = y->left;
    y->left = x;
    x->right = T2;
    updateBalance(x);
    updateBalance(y);
    return y;
}
struct node* balanceNode(struct node* node) {
    updateBalance(node);
    if (node->balance > 1) {
        if (node->left->balance < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (node->balance < -1) {
        if (node->right->balance > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}
struct node* push(struct node* root, int data) {
    if (root == NULL) {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        new_node->data = data;
        new_node->balance = 0;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent = NULL;
        return new_node;
    }
    if (data <= root->data)
        root->left = push(root->left, data);
    else
        root->right = push(root->right, data);
    return balanceNode(root);
}

struct node* root=NULL;

int main(void) {
    root = push(root, 3);
    root = push(root, 4);
    root = push(root, 2);
    root = push(root, 31);
    root = push(root, 334);
    return 0;
}
