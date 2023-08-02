#include <iostream>

struct node{
	int data;
	std::unique_ptr<node> next;
};

std::unique_ptr<node> head;

void add(int data) {
	if (head == nullptr) {
		head = std::make_unique<node>();
		head->data = data;
		head->next = nullptr;
		return;
	}
	node* current = head.get();
	while (current->next != nullptr) {
		current = current->next.get();
	}

	current->next = std::make_unique<node>();
	current->next->data = data;
	current->next->next = nullptr;
}
int get(int idx) {
	if (head == nullptr) {
		std::cout << "list is empty";
		return -1;
	}
	node* current = head.get();
	int current_idx = 0;
	while (current->next != nullptr && current_idx != idx) {
		current = current->next.get();
		current_idx++;
		    if (current_idx > idx) {
        std::cout << "Index out of bounds" << std::endl;
        return -1;
    }
	}
	return current->data;
}
int main() {
	add(1);
	add(2);
	add(3);
	add(4);
	std::cout<<get(2);
	return 0;
}