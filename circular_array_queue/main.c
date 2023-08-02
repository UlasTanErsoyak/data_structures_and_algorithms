#include <stdio.h>

#define size 10

int head = -1;
int tail = -1;
int queue[size];


void push(int data);
void pop();
int front();
int is_full();
int main() {

	front();
	push(2);
	printf("%d\n",front());
	push(3);
	printf("%d\n", front());
	pop();
	printf("%d\n", front());
	pop();
	push(1);
	push(2);
	push(3);
	push(4);
	push(5);
	push(6);
	push(7);
	push(8);
	push(9);
	push(10);
	printf("%d\n", front());
	pop();
	push(11);
	printf("%d\n", front());

}
void push(int data) {
	if (head == -1) {
		head++;
		tail++;
		queue[tail] = data;
	}
	else if (is_full() == 1) {
		printf("queue is full!");
		return;
	}
	else {
		queue[(tail + 1) % size] = data;
		tail = (tail+1)%10;
	}
}

void pop() {
	if (is_full() == 0) {
		printf("queue is empty\n");
	}
	if (head == tail) {
		head = -1;
		tail = -1;
	}
	else {
		head = (head + 1) % size;
	}
}

int front() {
	if (head==-1) {
		printf("queue is empty\n");
		return -1;
	}
	return queue[head];
}

int is_full() {
	if (((tail + 1) % size) == head) {
		return 1;
	}
	return 0;
}

